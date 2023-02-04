#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("data.inp", "r", stdin);

    int n, q;
    cin >> n >> q;

    vector<int> a(n), d(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int l, r;

    for (int i = 0; i < q; i++)
    {
        cin >> l >> r;
        l--, r--;

        d[l]++;
        if (r < n - 1)
            d[r + 1]--;
    }
    for (int i = 1; i < n; i++)
        d[i] += d[i - 1];

    sort(a.begin(), a.end());
    sort(d.begin(), d.end());

    long long ans = 0;
    for (int i = n - 1; i >= 0; i--)
        ans += 1LL * a[i] * d[i];

    cout << ans << endl;
    return 0;
}
