#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int n = s.size();
	map<char, set<int>> m;
	for (int i = 0; i < n; i++)
		m[s[i]].insert(i);

	int ans = 0;
	for (auto& x : m['1'])
	{
		auto pos2 = m['2'].lower_bound(x);
		if (pos2 == m['2'].end())
			continue;

		auto pos3 = m['3'].lower_bound(*pos2);
		if (pos3 == m['3'].end())
			continue;

		ans = max(ans, *pos3 - x);
	}

	cout << ans + 1 << endl;
	return EXIT_SUCCESS;
}
