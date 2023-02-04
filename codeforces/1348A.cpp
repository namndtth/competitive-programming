#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("data.inp", "r", stdin);

    int t; cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        set<int> save;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            save.insert(i);
        }
        if (save.size() > k)
            cout << "-1";
        else
        {
            for (int i = 0; i < n; i++)
            {
                set<int> used;
                for (int j = i; j < k; j++)

            }
        }

    }
}
