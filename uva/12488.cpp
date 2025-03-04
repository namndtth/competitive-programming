#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("data.inp", "r", stdin);

    int n, ans;

    vector<int> a, b, c;

    while (scanf("%d", &n) == 1)
    {
        ans = 0;

        a.resize(n);
        b.resize(n);
        c.resize(n);

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < n; i++)
            cin >> b[i];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (a[i] == b[j])
                    c[i] =  j;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
                if (c[i] < c[j])
                    ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
