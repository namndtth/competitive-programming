#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("data.inp", "r", stdin);
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        int a[n], b[n], prev_gcd;
        bool used[n] = {false};
        int mx = INT_MIN;
        int mx_idx = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] > mx)
            {
                mx = a[i];
                mx_idx = i;
            }
        }

        b[0] = mx;
        prev_gcd = b[0];
        a[mx_idx] = 0;

        for (int i = 1; i < n; i++)
        {
            int gcd = INT_MIN;
            int gcd_idx = -1;
            for (int j = 0; j < n; j++)
            {
                if (a[j] && (__gcd(prev_gcd, a[j]) > gcd))
                {

                    gcd = __gcd(prev_gcd, a[j]);
                    gcd_idx = j;
                }
            }
            b[i] = a[gcd_idx];
            prev_gcd = gcd;
            a[gcd_idx] = 0;
        }
        for (int i = 0; i < n; i++)
            cout << b[i] << " ";

        cout << "\n";
    }
    return 0;
}
