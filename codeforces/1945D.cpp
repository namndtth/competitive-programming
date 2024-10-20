#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll binaryOp(ll result, ll x)
{
    return result + x;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<ll> a(n), b(n);
    for (auto &x: a) cin >> x;
    for (auto &x: b) cin >> x;

    vector sum(n, 0LL);
    partial_sum(b.begin(), b.end(), sum.begin(), binaryOp);

    vector dp(n + 1, LLONG_MAX);
    dp[n] = 0;
    dp[n - 1] = a[n - 1];

    for (int i = n - 2; i >= 0; i--)
        for (int j = i + 1; j <= n; j++)
            dp[i] = min(dp[i], dp[j] + a[i] + (j == i + 1 ? 0 : sum[j - 1] - sum[i]));

    cout << *min_element(dp.begin(), dp.begin() + m) << endl;
}

void solve_greedy()
{
    int n, m;
    cin >> n >> m;

    vector<ll> a(n), b(n);
    for (auto &x: a) cin >> x;
    for (auto &x: b) cin >> x;

    vector sum(n, 0LL);
    partial_sum(b.begin(), b.end(), sum.begin(), binaryOp);

    ll ans{0LL};
    for (int i = n - 1; i >= m; i--) ans += min(a[i], b[i]);

    ll mn = LLONG_MAX;
    for (int i = m - 1; i >= 0; i--) mn = min(mn, a[i] + (m == i + 1 ? 0LL : sum[m - 1] - sum[i]));

    cout << ans + mn << endl;
}

int main()
{
    int tc;
    cin >> tc;

    while (tc--)
    {
        solve_greedy();
        // solve();
    }
    return EXIT_SUCCESS;
}
