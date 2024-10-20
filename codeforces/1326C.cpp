#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll mod = 998244353;

long long mul(ll x, ll y)
{
    return (x * y) % mod;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n), pos;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > n - k) pos.push_back(i);
    }

    long long ans1{1}, ans2{a[pos[0]]};
    for (int i = 1; i < static_cast<int>(pos.size()); i++)
    {
        ans1 = mul(ans1, pos[i] - pos[i - 1]);
        ans2 += a[pos[i]] * 1ll;
    }

    cout << ans2 << ' ' << ans1 << endl;
}

int main()
{
    solve();

    return EXIT_SUCCESS;
}
