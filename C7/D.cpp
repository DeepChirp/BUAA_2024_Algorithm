#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

auto main() -> int
{
    uint64_t n;
    cin >> n;
    vector<uint64_t> A(n);
    vector<uint64_t> B(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (size_t i = 0; i < n; i++)
    {
        cin >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    size_t index_a = 0, index_b = 0;
    uint64_t result = 0;
    while (index_a < n && index_b < n)
    {
        if (A[index_a] < B[index_b])
        {
            index_a++;
            index_b++;
            result++;
        }
        else
        {
            index_b++;
        }
    }
    cout << result;
}
