#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    freopen("data.inp", "r", stdin);

    int tc; cin >> tc;
    ll ans;

    while (tc--)
    {
        ll x, y, a, b;
        cin >> x >> y;
        cin >> a >> b;
        ll residual = max(x, y) - min(x, y);
        ans = min(residual * a + b * min(x, y), (x + y) * a);
        cout << ans << endl;
    }
    return 0;
}
