#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("data.inp", "r", stdin);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        set<int> exist;
        bool posible = true;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            // a[k] move to k + a[k mod n]
            if (exist.count(i + a[i % n]) == 0)
                exist.insert(i + a[i % n]);
            else
                posible = false;
        }
        if (!posible)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}
