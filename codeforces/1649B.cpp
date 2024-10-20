#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    int n;
    cin >> n;

    vector<ll> a(n);
    for (auto &x: a) cin >> x;

    sort(a.begin(), a.end());

    if (ll total = accumulate(a.begin(), a.end(), 0LL); total == 0) cout << 0 << endl;
    else
    {
        ll remaining = total - a.back();
        cout << 1 + (remaining >= a.back() ? 0 : a.back() - remaining - 1) << endl;
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
