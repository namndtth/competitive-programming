#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("data.inp", "r", stdin);

    int n; cin >> n;

    vector<int> a(n), f(n), dp;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int even = 1;

    for (int i = 0; i < n - 1; i++)
    {
        if (even)
        {
            f[i] = abs(a[i] + a[i + 1]);
            even ^= 1;
        }
        else
        {
            f[i] = abs(a[i] + a[i + 1]);
            f[i] = -f[i];
            even ^= 1;
        }
    }

    int ans = INT_MIN;

    for (int i = 0; i < n - 1; i++)
        cout << f[i] << " ";
    cout << endl;
    dp.assign(n, 0);

    for (int i = 1; i < n; i++)
    {
        dp[i] = dp[i - 1] + f[i - 1];
        if (dp[i] < 0)
            dp[i] = 0;
        ans = max(ans, dp[i]);
    }

    dp.assign(n, 0);

    for (int i = 1; i < n; i++)
    {
        dp[i] = dp[i - 1] + (-1) * f[i - 1];
        if (dp[i] < 0)
            dp[i] = 0;
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
