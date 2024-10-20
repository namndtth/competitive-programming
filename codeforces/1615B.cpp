#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_N = 200010;

bool comp(const pair<int, int> &p1, const pair<int, int> &p2)
{
    return p1.second < p2.second;
}

vector<vector<int> > build()
{
    vector cnt(MAX_N, vector<int>(20));

    for (int x = 1; x < MAX_N; x++)
        for (int i = 0; i < 20; i++)
            cnt[x][i] = x & 1 << i ? cnt[x - 1][i] + 1 : cnt[x - 1][i];

    return cnt;
}

void solve(const vector<vector<int> > &cnt)
{
    int l, r;
    cin >> l >> r;

    int ans = 0;
    for (int i = 0; i < 20; i++)
        ans = max(ans, cnt[r][i] - cnt[l - 1][i]);

    cout << (r - l + 1) - ans << endl;
}

int main()
{
    int tc;
    cin >> tc;

    auto cnt = build();
    while (tc--)
    {
        solve(cnt);
    }

    return EXIT_SUCCESS;
}
