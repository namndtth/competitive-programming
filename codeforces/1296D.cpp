#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("data.inp", "r", stdin);

    int n, a, b, k; cin >> n >> a >> b >> k;

    vector<int> hp(n);

    for (int i = 0; i < n; i++)
        cin >> hp[i];

    int total_damage = a + b;

    for (int i = 0; i < n; i++)
    {
        hp[i] = hp[i] % total_damage;
        if (hp[i] == 0)
            hp[i] = total_damage;
        hp[i] = ceil((float)hp[i] / (float)a) - 1;
    }

    sort(hp.begin(), hp.end());

    int num_k = 0;
    int ans = 0;

    for (auto e: hp)
        if (num_k + e <= k)
        {
            num_k += e;
            ans++;
        }
    cout << ans << endl;
    return 0;
}
