//
// Created by NAMND on 3/26/2023.
//
#include <bits/stdc++.h>
using namespace std;

struct node
{
	int left;
	int right;
};

int solve(vector<vector<node>>& nodes)
{
	int ans = 0;
	for (int h = (int)nodes.size() - 1; h > 0; h--)
	{
		int parent = h - 1;
		for (int j = 0; j < nodes[h].size(); j += 2)
		{
			if (nodes[h][j].right + 1 == nodes[h][j + 1].left)
				nodes[parent].push_back({ nodes[h][j].left, nodes[h][j + 1].right });
			else if (nodes[h][j].left == nodes[h][j + 1].right + 1)
			{
				nodes[parent].push_back({ nodes[h][j + 1].left, nodes[h][j].right });
				ans++;
			}
			else
			{
				ans = -1;
				return ans;
			}
		}
	}
	return ans;
}

void print(const vector<node>& nodes)
{
	for (const auto& e: nodes)
	{
		cout << e.left << " " << e.right << " ";
	}
}
int main()
{
	int t; cin >> t;
	while (t--)
	{
		int m, n;
		cin >> m;
		n = (int)log2(m);

		vector<vector<node>> nodes(n);
		vector<int> p(m);
		int ans = 0;
		int level = n - 1;
		for (int i = 0; i < m; i++)
			cin >> p[i];
		if (m == 1)
		{
			cout << 0 << endl;
			continue;
		}
		for (int i = 1; i < m; i++)
		{
			if ((i & 1) == 1)
			{
				if (ans == -1)
					continue;
				if (abs(p[i] - p[i - 1]) != 1)
					ans = -1;
				else
				{
					if (p[i] < p[i - 1])
					{
						swap(p[i], p[i - 1]);
						ans++;
					}
					nodes[level].push_back({ p[i - 1], p[i] });
				}
			}
		}
		int solver_ans = solve(nodes);
		if (ans == -1 || solver_ans == -1)
			cout << -1 << endl;
		else
			cout << ans + solver_ans << endl;
	}
	return EXIT_SUCCESS;
}