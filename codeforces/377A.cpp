#include <bits/stdc++.h>
using namespace std;

#define EMPTY 0
#define WALL 1
#define TRANSFORMED 2

vector<vector<int>> grid;
vector<vector<bool>> visited;

int n, m, k;

int movex[] = {0, 0, 1, -1};
int movey[] = {1, -1, 0, 0};

int s = 0, cnt = 0;

bool isSafe(int x, int y)
{
    return (x >= 0 && x < n &&
        y >= 0 && y < m &&
        grid[x][y] == EMPTY &&
        visited[x][y] == false);
}

void dfs(int x, int y)
{
    visited[x][y] = true;
    cnt++;
    if (cnt > s - k)
        grid[x][y] = TRANSFORMED;

    for (int i = 0; i < 4; i++)
    {
        if (isSafe(x + movex[i], y + movey[i]))
        {
            dfs(x + movex[i], y + movey[i]);
        }
    }
}

int main()
{
    // freopen("data.inp", "r", stdin);
    cin >> n >> m >> k;

    grid.assign(n, vector<int>(m, EMPTY));
    visited.assign(n, vector<bool>(m, false));

    char c;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> c;
            if (c == '.')
                s++;
            else
                grid[i][j] = WALL;
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == EMPTY && !visited[i][j])
                dfs(i, j);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == EMPTY)
                cout << '.';
            else if (grid[i][j] == WALL)
                cout << '#';
            else if (grid[i][j] == TRANSFORMED)
                cout << 'X';
        }
        cout << endl;
    }
    return 0;
}
