#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = ll(1e18);

void solve()
{
    int num_trees, num_colors, beauty;
    cin >> num_trees >> num_colors >> beauty;

    vector<int> c(101);
    for (int i = 1; i <= num_trees; i++)
        cin >> c[i];

    vector<vector<int>> p(101, vector<int>(101));
    for (int i = 1; i <= num_trees; i++)
        for (int j = 1; j <= num_colors; j++)
            cin >> p[i][j];

    vector<vector<vector<ll>>> dp(101, vector<vector<ll>>(101, vector<ll>(101)));

    for (int i = 0; i <= num_trees; i++)
    {
        for (int j = 0; j <= num_colors; j++)
        {
            for (int a = 0; a <= beauty; a++)
            {
                dp[i][j][a] = INF;
            }
        }
    }
    if (c[1] == 0)
    {
        for (int j = 1; j <= num_colors; j++)
            dp[1][j][1] = p[1][j];
    }
    else
    {
        dp[1][c[1]][1] = 0;
    }

    for (int i = 2; i <= num_trees; i++)
    {
        for (int k = 1; k <= beauty; k++)
        {
            if (c[i] == 0)
            {
                for (int j = 1; j <= num_colors; j++)
                {// consider case i-th tree's is uncolored then color same color with i-1-th tree
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k] + p[i][j]);
                    // different colors
                    for (int prev_color = 1; prev_color <= num_colors; prev_color++)
                    {
                        if (prev_color != j)
                            dp[i][j][k] = min(dp[i][j][k], dp[i - 1][prev_color][k - 1] + p[i][j]);
                    }
                }
            }
            else
            {
                dp[i][c[i]][k] = min(dp[i][c[i]][k], dp[i - 1][c[i]][k]);
                for (int b = 1; b <= num_colors; b++)
                    if (b != c[i])
                        dp[i][c[i]][k] = min(dp[i][c[i]][k], dp[i - 1][b][k - 1]);

            }

        }
    }
    ll ans = INF;
    for (int j = 1; j <= num_colors; j++)
        ans = min(ans, dp[num_trees][j][beauty]);
    cout << (ans == INF ? -1 : ans) << endl;
}

int main()
{
    solve();
    return EXIT_SUCCESS;
}