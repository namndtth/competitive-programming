#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n;
	cin >> n;

	vector<int> a(n);
	map<int, int> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		m.emplace(a[i], i + 1);
	}

	int ans = 0;
	for (auto& [x, i] : m)
	{
		auto lower = m.lower_bound(2 * n / x);

		auto it = m.begin();
		while (true)
		{
			if (x * it->first == i + it->second && i != it->second)
				ans++;

			if (it++ == lower)
				break;
		}
	}

	cout << ans / 2 << endl;
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
