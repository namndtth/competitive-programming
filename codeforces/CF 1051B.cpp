#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
vector<ii> ans;
map<ll, ll> exist;
ll gcd(ll a, ll b)
{
    return (b == 0 ? a : gcd(b, a % b));
}
int main()
{
    ios::sync_with_stdio(false);cout.tie(0);
    ll c = 0;
    ll l, r;
    ll i, j;

    cin >> l >> r;
    ll mid = (r - l + 1) / 2;
    for (i = l; i <= r; i++)
    {
        for (j = i + 1; j <= r; j++)
        {
            if (exist.count(j) != 0 || exist.count(i) != 0)
                break;
            if (gcd(i, j) == 1)
            {
                c++;
                ans.push_back(ii(i, j));
                exist[i]++;
                exist[j]++;
            }
            if (c == mid)
            {
                cout << "YES\n";
                for (ll k = 0; k < c; k++)
                    cout << ans[k].first << " " << ans[k].second << "\n";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}
