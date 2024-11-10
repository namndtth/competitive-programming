#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    ll n, c, d;
    cin >> n >> c >> d;

    vector<ll> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());

    ll ans{LLONG_MAX};
    for (int i = 1; i <= s.size(); i++)
    {
        ans = min<ll>(ans, (n - i) * c + (s[i - 1] - i) * d);
    }

    ans = min(ans, n * c + d);

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--)
    {
        solve();
    }

    return EXIT_SUCCESS;
}
