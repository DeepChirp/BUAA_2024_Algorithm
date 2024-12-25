#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

auto compute_pi(const string &str) -> vector<uint64_t>
{
    const size_t N = str.length();
    vector<uint64_t> pi(N);

    for (size_t i = 1; i < N; ++i)
    {
        uint64_t j = pi[i - 1];
        while (j > 0 && str[i] != str[j])
        {
            j = pi[j - 1];
        }
        if (str[i] == str[j])
        {
            j++;
        }
        pi[i] = j;
    }

    return pi;
}

auto main() -> int
{
    uint64_t T;
    cin >> T;
    for (size_t i = 0; i < T; i++)
    {
        string str;
        cin >> str;

        vector<uint64_t> pi = compute_pi(str);
        for (size_t j = 0; j < str.length(); ++j)
        {
            if (j > 0)
            {
                cout << " ";
            }
            cout << pi[j];
        }
        cout << "\n";
    }

    return 0;
}
