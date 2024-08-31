//
// Created by nampc on 10/19/2023.
//
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORN(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, b, a) for (int i = b - 1; i >= a; i--)
#define FORDN(i, b, a) for (int i = b; i >= a; i--)

using ll = long long;

int main()
{
	int n, m, d;
	cin >> n >> m >> d;

	vector<int> a(n);
	set<pair<int, int>> s;
	FOR(i, 0, n)
	{
		cin >> a[i];
		s.insert({ a[i], i });
	}
	int day = 1;
	vector<int> ans(n);
	while (!s.empty())
	{
		int pos = s.begin()->second;
		ans[pos] = day;
		s.erase(s.begin());
		while (true)
		{
			auto it = s.lower_bound({ a[pos] + d + 1, 0 });
			if (it == s.end())
				break;
			pos = it->second;
			ans[pos] = day;
			s.erase(it);
		}
		day++;
	}
	cout << day - 1 << endl;
	FOR(i, 0, n)
		cout << ans[i] << " ";
	return EXIT_SUCCESS;
}
