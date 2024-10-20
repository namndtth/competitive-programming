#include <bits/stdc++.h>

using namespace std;

void bfs(vector<string>& board, int n, int m, int i, int j)
{
	vector<pair<int, int>> d{{ -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 }};

	queue<tuple<int, int, char>> q;
	q.emplace(i, j, 'W');

	while (!q.empty())
	{
		auto [u, v, c] = q.front();
		q.pop();

		if (board[u][v] != '.')
			continue;

		board[u][v] = c;

		for (const auto& [x, y] : d)
		{
			int newU = u + x;
			int newV = v + y;
			if (0 <= newU && newU < n && 0 <= newV && newV < m && board[newU][newV] == '.')
			{
				q.emplace(newU, newV, c == 'W' ? 'B' : 'W');
			}

		}
	}
}


int main()
{
	int n, m;
	cin >> n >> m;

	vector<string> board(n);
	for (int i = 0; i < n; i++)
		cin >> board[i];

	for (int x = 0; x < n; x++)
		for (int y = 0; y < m; y++)
			if (board[x][y] == '.')
				bfs(board, n, m, x, y);

	for (const auto& row : board)
		cout << row << endl;

	return EXIT_SUCCESS;
}
