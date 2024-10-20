#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void print_array(const vector<ll>& v)
{
    for (const auto& x: v) cout << x << ' ';
    cout << endl;
}

void solve()
{
    int n;
    cin >> n;

    int ans{0};
    multiset<ll> s;
    ll target{(1LL << 31) - 1};
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (auto it = s.find(target ^ x); it != s.end()) s.erase(it);
        else
        {
            s.insert(x);
            ans++;
        }
    }
    cout << ans << endl;
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
