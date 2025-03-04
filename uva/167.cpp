#include <bits/stdc++.h>
using namespace std;

#define MAX 8

vector<vector<int>> board;
vector<int> row(MAX);
int ans;

bool can_place(int r, int c)
{
    for (int i = 0; i < c; i++)
    {
        if (row[i] == r || (abs(i - c) == abs(row[i] -r)) )
            return false;
    }
    return true;
}
void backtrack(int c)
{
    if (c == MAX)
    {
        // printf("Found a configuration\n");
        int total = 0;
        for (int i = 0; i < MAX; i++)
        {
            //cout << board[row[i]][i] << endl;
            total += board[row[i]][i];
        }
        ans = max(ans, total);
        return;
    }
    for (int r = 0; r < MAX; r++)
    {
        if (can_place(r, c))
        {
            row[c] = r;
            backtrack(c + 1);
        }
    }
}
int main()
{
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
    int k;cin >> k;

    while (k--)
    {
        row.clear();

        ans = INT_MIN;

        board.assign(8, vector<int> (8));

        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
                cin >> board[i][j];
        }
        backtrack(0);
        printf("%5d\n", ans);
    }
    return 0;
}
