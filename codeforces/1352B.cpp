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
        vector<int> res;

        res.assign(k, n / k);

        int pre = n - (k - 1);
        int suf = n - pre * (k - 1);
        if ((n - k + 1) % 2 != 0 && (n - k + 1) > 0)
        {
            cout << "YES\n";
            for (int i = 0; i < k - 1; i++)
                cout << 1 << " ";
            cout << n - (k - 1) << endl;
        }
        else if ((n - 2 * k + 2) % 2 == 0 && (n - 2 * k + 2) > 0)
        {
            cout << "YES\n";
            for (int i = 0; i < k - 1; i++)
                cout << 2 << " ";
            cout << n - 2 * (k - 1) << endl;
        }
        else cout << "NO\n";
    }
    return 0;
}
