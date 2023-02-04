#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f[40000 + 50];

ll calc(ll p, ll n)
{
    ll res = (p / n) * f[n] + f[p % n];
    return res;
}

int main()
{
    // freopen("data.inp", "r", stdin);

    ll t; cin >> t;
    while (t--)
    {
        ll a, b, queries;

        cin >> a >> b >> queries;

        ll n = a * b;

        f[0] = 0;

        for (ll i = 1; i <= n; i++)
        {
            if (i % a % b != i % b % a)
                f[i] = f[i - 1] + 1;
            else
                f[i] = f[i - 1];
        }

        for (ll q = 0; q < queries; q++)
        {
            ll l, r;
            cin >> l >> r;
            ll ans = calc(r, n) - calc(l - 1, n);
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}
