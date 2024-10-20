#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll cal_delivery_distance(const vector<ll>& v, int k)
{
    ll res{0};
    for (int i = 0; i < static_cast<int>(v.size()); i += k) res += v[i];

    return abs(res);
}

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<ll> pos, neg;
    ll x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x >= 0) pos.push_back(x);
        else neg.push_back(x);
    }

    sort(pos.begin(), pos.end(), std::greater<ll>());
    sort(neg.begin(), neg.end(), std::less<ll>());

    ll pos_deli_distance = cal_delivery_distance(pos, k);
    ll neg_deli_distance = cal_delivery_distance(neg, k);
    ll last_distance = max(pos.empty() ? 0 : pos.front(), neg.empty() ? 0 : -neg.front());
    cout << 2 * (pos_deli_distance + neg_deli_distance) - last_distance << endl;
}

int main()
{
    int tc;
    cin >> tc;

    while (tc--)
    {
        solve();
    }

    return EXIT_SUCCESS;
}
