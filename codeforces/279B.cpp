#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    int n, t;
    cin >> n >> t;

    vector<ll> a(n);
    for (auto& x: a) cin >> x;

    vector<ll> s(n + 1, 0);
    partial_sum(a.begin(), a.end(), s.begin() + 1);

    ll ans{0};
    for (int i = 0; i <= n; i++)
    {
        auto p = upper_bound(s.begin(), s.end(), s[i] + t) - s.begin();
        ans = max<ll>(ans, p - i - 1);
    }

    cout << ans << endl;
}

int main()
{
    solve();

    return EXIT_SUCCESS;
}
