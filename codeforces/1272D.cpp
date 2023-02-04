#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("data.inp", "r", stdin);

    int n; cin >> n;

    vector<int> a(n + 2);

    a[0] = INT_MIN;
    a[n + 1] = INT_MAX;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<int> asc(n + 2, 1);
    vector<int> des(n + 2, 1);

    asc[0] = des[n + 1] = 0;

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        if (a[i - 1] < a[i])
            asc[i] = asc[i - 1] + 1;
        ans = max(ans, asc[i]);
    }

    for (int i = n; i >= 1; i--)
    {
        if (a[i] < a[i + 1])
            des[i] = des[i + 1] + 1;
        ans = max(ans, des[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        if (a[i - 1] < a[i + 1])
            ans = max(ans, asc[i - 1] + des[i + 1]);
    }
    cout << ans << endl;
    return 0;
}
