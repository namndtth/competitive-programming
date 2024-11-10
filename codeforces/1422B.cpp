#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll numOps(vector<ll> v)
{
    sort(v.begin(), v.end());
    double med = (v[v.size() / 2 - 1] + v[v.size() / 2]) / 2.0;

    double res{0.0};
    for (ll x: v) res += abs(x - med);

    return res;
}


void solve()
{
    int N, M;
    cin >> N >> M;

    vector<vector<ll>> m(N, vector<ll>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> m[i][j];

    ll ans{0};
    for (int i = 0; i < N / 2; i++)
        for (int j = 0; j < M / 2; j++)
            ans += numOps({m[i][j], m[N - 1 - i][j], m[i][M - 1 - j], m[N - 1 - i][M - 1 - j]});

    if (N & 1)
        for (int j = 0; j < M / 2; j++)
            ans += numOps({m[N / 2][j], m[N / 2][M - 1 - j]});

    if (M & 1)
        for (int i = 0; i < N / 2; i++)
            ans += numOps({m[i][M / 2], m[N - 1 - i][M / 2]});

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
