#include <bits/stdc++.h>

#define ll long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];

    vector<string> sts(n);
    for (int i = 0; i < n; i++)
        cin >> sts[i];

    vector<vector<ll>> dp(n, vector<ll>(2, LLONG_MAX));

    dp[0][0] = 0;
    dp[0][1] = c[0];

    for (int i = 1; i < n; i++)
    {
        string prev_reversed = sts[i - 1];
        string current_reversed = sts[i];

        std::reverse(prev_reversed.begin(), prev_reversed.end());
        std::reverse(current_reversed.begin(), current_reversed.end());

        if (sts[i] >= sts[i - 1]) dp[i][0] = dp[i - 1][0];
        if (sts[i] >= prev_reversed) dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        if (current_reversed >= sts[i - 1]) dp[i][1] = (dp[i - 1][0] == LLONG_MAX) ? dp[i - 1][0] : dp[i - 1][0] + c[i];
        if (current_reversed >= prev_reversed)
            dp[i][1] = min(dp[i][1], dp[i - 1][1] == LLONG_MAX ? dp[i - 1][1] : dp[i - 1][1] + c[i]);
    }
    cout << ((min(dp[n - 1][0], dp[n - 1][1]) == LLONG_MAX) ? -1 : min(dp[n - 1][0], dp[n - 1][1])) << endl;
}

int main()
{
    solve();
    return EXIT_SUCCESS;
}