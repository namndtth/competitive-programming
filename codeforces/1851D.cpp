#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    int n;
    cin >> n;

    vector<ll> a(n - 1);
    for (auto& x: a) cin >> x;

    unordered_map<ll, int> p{make_pair(a[0], 1)};
    for (int i = 1; i < n - 1; i++) p[a[i] - a[i - 1]]++;

    vector<ll> ms;
    for (int i = 1; i <= n; i++) if (!p[i]) ms.push_back(i);

    if (ms.size() == 1) cout << "YES\n";
    else if (ms.size() == 2)
    {
        if (ll s{ms[0] + ms[1]}; (s <= n && p[s] == 2) || (s > n && p[s] == 1)) cout << "YES\n";
        else cout << "NO\n";
    }
    else cout << "NO\n";
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
