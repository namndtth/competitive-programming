#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("data.inp", "r", stdin);

    int t;
    cin >> t;

    while (t--)
    {
        int a, K;

        cin >> a >> K;

        vector<int> ans;
        ans.push_back(a);

        if (K == 1)
            cout << ans[0] << endl;
        else
            for (int i = 1; i < K; i++)
            {
                int mx = INT_MIN;
                int mn = INT_MAX;

                while (a[i - 1] > 0)
                {
                    int mod = a % 10;
                    mx = max(mx, mod);
                    mn = min(mn, mod);
                    a /= 10;
                }
                //cout << mn << " " << mx << endl;
                a = prev + mn * mx;
                //cout << a << endl;
            }
        cout << a << endl;
    }

    return 0;
}
