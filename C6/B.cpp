#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

namespace
{
auto reverse_bits(uint64_t n, uint64_t k) -> uint64_t
{
    uint64_t result = 0;
    for (size_t i = 0; i < k; i++)
    {
        if ((n & (1ULL << i)) != 0U)
        {
            result |= (1ULL << (k - i - 1));
        }
    }
    return result;
}
} // namespace

int main()
{
    uint64_t n;
    cin >> n;
    vector<uint64_t> a(n);
    uint64_t k = 0;

    uint64_t temp = n;
    while ((temp >>= 1) != 0U)
    {
        k++;
    }

    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<uint64_t> a_rev(n);
    for (size_t i = 0; i < n; i++)
    {
        uint64_t rev_i = reverse_bits(i, k);
        a_rev[i] = a[rev_i];
    }

    for (size_t i = 0; i < n; i++)
    {
        cout << a_rev[i];
        if (i != n - 1)
        {
            cout << " ";
        }
    }
    cout << '\n';

    return 0;
}
