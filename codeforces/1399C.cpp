#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n;
	cin >> n;

	map<int, int> m;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		m[x]++;
	}

	int ans = 0;
	for (int i = 1; i <= 100; i++)
	{
		auto m_copy = m;
		int teams = 0;
		for (auto [w, cnt] : m_copy)
		{
			if (m_copy[i - w])
			{
				if (i - w == w)
					teams += m_copy[w] / 2;
				else
				{
					teams += min(cnt, m_copy[i - w]);
					m_copy[w] -= min(cnt, m_copy[i - w]);
					m_copy[i - w] -= min(cnt, m_copy[i - w]);
				}
			}
		}
		ans = max(ans, teams);
	}

	cout << ans << endl;
}

int main()
{
	int tc;
	cin >> tc;

	while (tc--)
	{
		solve();
	}

	return EXIT_SUCCESS;
}
