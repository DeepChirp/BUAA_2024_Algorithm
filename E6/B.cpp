#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

auto compute_pi(const string &pattern) -> vector<uint64_t>
{
    const size_t M = pattern.length();
    vector<uint64_t> pi(M);

    for (size_t i = 1; i < M; ++i)
    {
        uint64_t j = pi[i - 1];
        while (j > 0 && pattern[i] != pattern[j])
        {
            j = pi[j - 1];
        }
        if (pattern[i] == pattern[j])
        {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

auto kmp_search(const string &text, const string &pattern) -> vector<uint64_t>
{
    vector<uint64_t> positions;
    vector<uint64_t> pi = compute_pi(pattern);
    uint64_t j = 0;

    for (size_t i = 0; i < text.length(); ++i)
    {
        while (j > 0 && text[i] != pattern[j])
        {
            j = pi[j - 1];
        }
        if (text[i] == pattern[j])
        {
            j++;
        }
        if (j == pattern.length())
        {
            positions.push_back(i - pattern.length() + 2);
            j = pi[j - 1];
        }
    }
    return positions;
}

auto main() -> int
{
    uint64_t T;
    cin >> T;

    for (size_t i = 0; i < T; ++i)
    {
        string text, pattern;
        cin >> text >> pattern;

        auto positions = kmp_search(text, pattern);
        cout << positions.size();
        for (const auto POS : positions)
        {
            cout << " " << POS;
        }
        cout << "\n";
    }
    return 0;
}
