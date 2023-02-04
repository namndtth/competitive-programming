#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
vector<int> c;
vector<string> vs;
vector<vector<long long>> dp;
int n;

long long solve()
{
    for (int i = 1; i < n; i++)
    {
        string st_prev = vs[i - 1].c_str();
        string st_prev_rv = vs[i - 1].c_str();
        reverse(st_prev_rv.begin(), st_prev_rv.end());

        string st_cur = vs[i].c_str();
        string st_cur_rv = vs[i].c_str();
        reverse(st_cur_rv.begin(), st_cur_rv.end());

        if (st_cur >= st_prev)
            dp[i][0] = min(dp[i][0], dp[i - 1][0] != LLONG_MAX ? dp[i - 1][0] : LLONG_MAX);
        if (st_cur >= st_prev_rv)
            dp[i][0] = min(dp[i][0], dp[i - 1][1] != LLONG_MAX ? dp[i - 1][1] : LLONG_MAX);

        if (st_cur_rv >= st_prev)
            dp[i][1] = min(dp[i][1], dp[i - 1][0] != LLONG_MAX ? dp[i - 1][0] + c[i] : LLONG_MAX);
        if (st_cur_rv >= st_prev_rv)
            dp[i][1] = min(dp[i][1], dp[i - 1][1] != LLONG_MAX ? dp[i - 1][1] + c[i]: LLONG_MAX);

    }
    return min(dp[n - 1][0], dp[n - 1][1]);
}

int main()
{
    // freopen("data.inp", "r", stdin);
    cin >> n;

    c.resize(n);
    vs.resize(n);

    for (int i = 0; i < n; i++)
        cin >> c[i];

    for (int i = 0; i < n; i++)
        cin >> vs[i];

    dp.assign(N, vector<long long>(2, LLONG_MAX));

    dp[0][0] = 0;
    dp[0][1] = c[0];

    long long ans = solve();

    if (ans != LLONG_MAX)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}

