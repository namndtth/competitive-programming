#include <bits/stdc++.h>
using namespace std;

int get_length_longest_block(const vector<vector<int>>& cnt, int n, char c)
{
    const vector<int>& occurrences = cnt[c - 'a'];

    int res = max(occurrences.front(), n - 1 - occurrences.back());
    for (int i = 1; i < occurrences.size(); i++) res = max(res, occurrences[i] - occurrences[i - 1] - 1);

    return res;
}

int compute_num_ops(int length)
{
    int res{0};
    while (length > 0)
    {
        length /= 2;
        res++;
    }

    return res;
}

void solve()
{
    string s;
    cin >> s;

    vector<vector<int>> cnt(26);
    for (int i = 0; i < s.size(); i++) cnt[s[i] - 'a'].push_back(i);

    int ans = INT_MAX;
    for (char c = 'a'; c <= 'z'; c++)
    {
        if (cnt[c - 'a'].empty())
            continue;

        int length = get_length_longest_block(cnt, s.size(), c);
        ans = min(ans, compute_num_ops(length));
    }

    cout << ans << endl;
}

int main()
{
    int tc;
    cin >> tc;

    while (tc--)
    {
        solve();
    }

    return EXIT_SUCCESS;
}
