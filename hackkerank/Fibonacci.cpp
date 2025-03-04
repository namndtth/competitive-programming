#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = ll(1e18);
const ll mod = ll(1e9) + 7;
int main()
{
    ll n;
    cin >> n;
    ll f0 = 0, f1 = 1, f2;
    for (ll i = 1;i <= n; i++)
    {
        f2 = (f0 + f1) % mod;
        f0 = f1;
        f1 = f2;
    }
    cout << f2;
    return 0;
}
