#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    ll n, w;
    cin >> n >> w;

    vector<pair<ll, ll>> items(n);
    for (int i = 0; i < n; i++)
    {
        auto& [w, idx] = items[i];
        cin >> w;
        idx = i + 1;
    }

    sort(items.begin(), items.end());

    ll half_w = ceil(w * 1.0 / 2.0);

    auto it = upper_bound(items.begin(), items.end(), make_pair(half_w, 0LL));
    if (it != items.end() && half_w <= it->first && it->first <= w)
        cout << 1 << endl << it->second << endl;
    else
    {
        vector<ll> ans;
        ll total_w{0};
        for (int i = it - items.begin() - 1; i >= 0; --i)
        {
            total_w += items[i].first;
            ans.push_back(items[i].second);
            if (total_w >= half_w) break;
        }

        if (total_w >= half_w)
        {
            cout << ans.size() << endl;
            for (int x: ans) cout << x << ' ';
            cout << endl;
        } else cout << -1 << endl;
    }
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
