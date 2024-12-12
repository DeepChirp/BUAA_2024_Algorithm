#include <cmath>
#include <complex>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

namespace
{
const double PI = acos(-1.0);

void fft(vector<complex<double>> &a, size_t n, bool invert)
{
    for (size_t i = 1, j = 0; i < n; i++)
    {
        size_t bit = n >> 1;
        while ((j & bit) != 0U)
        {
            j ^= bit;
            bit >>= 1;
        }
        j ^= bit;

        if (i < j)
        {
            swap(a[i], a[j]);
        }
    }

    for (size_t len = 2; len <= n; len <<= 1)
    {
        double angle = 2 * PI / static_cast<double>(len) * (invert ? -1 : 1);
        complex<double> omega_n(cos(angle), sin(angle));
        for (size_t i = 0; i < n; i += len)
        {
            complex<double> omega(1);
            for (size_t j = 0; j < len / 2; ++j)
            {
                complex<double> u = a[i + j];
                complex<double> v = omega * a[i + j + (len / 2)];
                a[i + j] = u + v;
                a[i + j + (len / 2)] = u - v;
                omega *= omega_n;
            }
        }
    }

    if (invert)
    {
        for (size_t i = 0; i < n; i++)
        {
            a[i] /= static_cast<double>(n);
        }
    }
}
} // namespace

int main()
{
    int32_t n;
    cin >> n;
    auto N = static_cast<size_t>(1ULL << n);
    vector<int32_t> c(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> c[i];
    }

    vector<complex<double>> a(N);
    for (size_t i = 0; i < N; i++)
    {
        a[i] = complex<double>(static_cast<double>(c[i]), 0.0);
    }

    fft(a, N, false);

    complex<double> z(0.0, 0.0);
    for (size_t k = 0; k < N; k++)
    {
        double cos_k = cos(static_cast<double>(k));
        z += a[k] * cos_k;
    }

    cout << fixed << setprecision(2) << z.real() << " " << z.imag() << '\n';
    return 0;
}
