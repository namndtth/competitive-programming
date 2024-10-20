//
// Created by NAMND on 4/23/2023.
//
#include <bits/stdc++.h>

#define ll long long
#define modulo (ll)(1e9 + 7)
using namespace std;

vector<ll> dp(1e5 + 10, 1LL);

void constructDP(int k)
{
    for (ll i = 1; i <= (ll) 1e5; i++)
    {
        if (i - k >= 0)
            dp[i] += dp[i - k] + dp[i - 1];
        else
            dp[i] += dp[i - 1];

        if (dp[i] >= modulo)
            dp[i] -= modulo;
    }
}

void solve(int k)
{
    int l, r;
    cin >> l >> r;
    cout << (dp[r] - dp[l - 1] + modulo) % modulo << endl;
}

int main()
{
    int t, k;
    cin >> t >> k;
    constructDP(k);
    while (t--)
    {
        solve(k);
    }

    return EXIT_SUCCESS;
}