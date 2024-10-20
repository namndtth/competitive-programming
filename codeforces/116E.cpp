#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
const int MOD = 1e9 + 7;

typedef long long ll;

int main()
{
    int n; cin >> n;
    vector<ll> prev(4);
    vector<ll> dp(4);

    prev[0] = prev[1] = prev[2] = 0;
    prev[3] = 1;

    for (int i = 1; i <= n; i++)
    {
        dp[0] = (prev[1] + prev[2] + prev[3]) % MOD;
        dp[1] = (prev[0] + prev[2] + prev[3]) % MOD;
        dp[2] = (prev[0] + prev[1] + prev[3]) % MOD;
        dp[3] = (prev[0] + prev[1] + prev[2]) % MOD;
        prev = dp;
    }
    cout << dp[3] << endl;
    return 0;
}
