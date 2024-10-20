//
// Created by nampc on 10/22/2023.
//
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORN(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, b, a) for (int i = b - 1; i >= a; i--)
#define FORDN(i, b, a) for (int i = b; i >= a; i--)

using vi = vector<int>;
using vvi = vector<vector<int>>;
using ll = long long;

int main()
{
	int n;
	cin >> n;
	vi a(n);
	FOR(i, 0, n) cin >> a[i];
	sort(a.begin(), a.end());

	set<int> s;
	FOR(i, 0, n)
	{
		if (a[i] - 1 > 0 && !s.count(a[i] - 1))
			s.insert(a[i] - 1);
		else if (!s.count(a[i]))
			s.insert(a[i]);
		else s.insert(a[i] + 1);
	}
	cout << s.size() << endl;
	return EXIT_SUCCESS;
}
