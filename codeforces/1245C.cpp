#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;
int main()
{
    // freopen("data.inp", "r", stdin);

    string st; cin >> st;

    int n = (int)st.size();

    vector<long long> dp(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (st[i - 1] == 'w' || st[i - 1] == 'm')
        {
            cout << "0\n";
            return 0;
        }
    }

    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        if ((st[i - 1] == 'u' && st[i - 2] == 'u') || (st[i - 1] == 'n' && st[i - 2] == 'n'))
            dp[i] = dp[i - 1] + dp[i - 2];
        else
            dp[i] = dp[i - 1];
        if (dp[i] > mod)
            dp[i] -= mod;
    }
    cout << dp[n] << endl;
    return 0;
}
