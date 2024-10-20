#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll acc_map(ll value, const pair<ll, ll> &rhs)
{
    return value + rhs.second;
}

void solve()
{
    int n;
    cin >> n;

    vector<ll> a(n), b(n);
    for (auto &x: a) cin >> x;
    for (auto &x: b) cin >> x;

    map<ll, ll> cnt;
    for (int i = 0; i < n; ++i) if (a[i] != b[i]) cnt[b[i]]++;

    int m;
    cin >> m;

    int x;
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        if (cnt[x]) cnt[x]--;
        if (i == m - 1)
        {
            if (find(b.begin(), b.end(), x) == b.end() || accumulate(cnt.begin(), cnt.end(), 0LL, acc_map) != 0)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
    }
}

int main()
{
    int tc;
    cin >> tc;
    // tc = 1;
    while (tc--)
    {
        solve();
    }

    return EXIT_SUCCESS;
}
