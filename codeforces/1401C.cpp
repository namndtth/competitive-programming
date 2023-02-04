#include <bits/stdc++.h>
using namespace std;

const int MAX = int(1e5) + 20;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int a[MAX], b[MAX];

        int n; cin >> n;
        int mina = INT_MAX;
        bool isSatisfy = true;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
            mina = min(mina, a[i]);
        }

        sort(b, b + n);
        for (int i = 0; i < n; i++)
        {
            if ((a[i] != b[i]) && (a[i] % mina != 0))
                isSatisfy = false;
        }

        if (isSatisfy)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
