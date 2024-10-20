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
        vector<int> m(n);
        set<int> used_values;
        for (int i = 0; i < n; i++)
        {
            cin >> m[i];
            used_values.insert(m[i]);
        }

        int mx = *(used_values.rbegin());
        int mn = *(used_values.begin());

        if ((int)used_values.size() > k)
            cout << "-1\n";
        else
        {
            for (int i = 1; i <= n; i++)
            {
                if ((int)used_values.size() != k)
                    used_values.insert(i);
            }
            cout << n * (int)used_values.size() << endl;
            for (int i = 0; i < n; i++)
            {
                for (auto it = used_values.begin(); it != used_values.end(); it++)
                    cout << *it << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
