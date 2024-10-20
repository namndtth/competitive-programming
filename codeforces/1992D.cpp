#include <bits/stdc++.h>
using namespace std;

const int inf = INT32_MAX;

void solveDp()
{
	int n, m, k;
	cin >> n >> m >> k;

	string a;
	cin >> a;

	a.insert(a.begin(), 'L');
	a.insert(a.end(), 'L');


	// min swim to reach i-th cell
	vector<int> dp(n + 10, inf);
	dp[0] = 0;

	for (int i = 1; i < a.size(); i++)
	{
		if (a[i] == 'C')
		{
			dp[i] = inf;
			continue;
		}

		dp[i] = (dp[i - 1] == inf ? inf : dp[i - 1] + 1);
		for (int j = 1; j <= m; j++)
		{
			if (i - j >= 0)
			{
				if (a[i - j] == 'C')
					continue;

				if (a[i - j] == 'L')
					dp[i] = min(dp[i], dp[i - j]);
			}

		}
	}

	if (dp[n + 1] == inf || dp[n + 1] > k)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
}

void solveGreedy()
{
	int n, m, k;
	cin >> n >> m >> k;

	string a;
	cin >> a;

	vector<int> logs;
	for (int i = 0; i < n; i++)
		if (a[i] == 'L')
			logs.push_back(i);
	logs.push_back(n + 1);

	int i = -1, next_logs = 0;
	while (i < n)
	{
		if (m >= logs[next_logs] - i)
			i = logs[next_logs];
		else
		{
			i += m;
			while (i < n && i < logs[next_logs])
			{
				if (a[i] != 'C' and k > 0)
				{
					i += 1;
					k -= 1;
				}
				else
				{
					cout << "NO" << endl;
					return;
				}
			}
		}
		next_logs += 1;
	}
	cout << "YES" << endl;
}

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		solveGreedy();
	}
	return 0;
}

