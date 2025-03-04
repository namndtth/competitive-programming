// Link to SPOJ problem:
// https://www.spoj.com/problems/ASSIGN/

#include <bits/stdc++.h>
using namespace std;

const int N = 210;

void assign(N, cost)
{
    for (int i = 0; i <= N; i++)
        assignment[i] = i;
    int res = INT_MAX;
    for (int i = 0; i < N!; i++)

}

int main()
{
    freopen("data.inp", "r", stdin);

    int n; cin >> n;
    int c[N][N];

    // assign person i-th for work j-th
    int work[N][N];

    c.assign(n, vector<int>(n));

    for (int i = 0; i < n; ++)
        for (int j = 0; j < n; j++)
            cin >> c[i][j];
    for (int i = 0; i < n; i++)
    {
        work[0][i]
        for (int j = 0; j < n; j++)
            if (j == work[i])

                work[i] = min(c[i][j]);
    }
}
