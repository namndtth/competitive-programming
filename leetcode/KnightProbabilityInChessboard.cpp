//
// Created by nampc on 11/4/2023.
//
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORN(i, a, b) for (int i = a; i <= b; i++)
#define FORR(i, b, a) for (int i = b - 1; i >= a; i--)
#define FORRN(i, b, a) for (int i = b; i >= a; i--)

using vi = vector<int>;
using vvi = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vii = vector<pair<int, int>>;

class Solution
{
	int x_move[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	int y_move[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int in = 0, out = 0;
public:
	double knightProbability(int n, int k, int row, int column)
	{
		move(n, k, 0, row, column);
		cout << in << " " << out << endl;
		cout << in * 1.0 / (in + out) << endl;
	}

	void move(int n, int k, int num_moves, int x, int y)
	{
		if (!onBoard(n, x, y))
		{
			out++;
			return;
		}

		if (num_moves == k && onBoard(n, x, y))
		{
			in++;
			return;
		}

		FOR(j, 0, 8)
		{
			move(n, k, num_moves + 1, x + x_move[j], y + y_move[j]);
		}
	}

	bool onBoard(int n, int x, int y)
	{
		return x >= 0 && y >= 0 && x < n && y < n;
	}
};

int main()
{
	int n, k, row, column;
	cin >> n >> k >> row >> column;
	Solution sol;
	sol.knightProbability(n, k, row, column);
	return EXIT_SUCCESS;
}
