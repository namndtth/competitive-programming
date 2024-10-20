//
// Created by nampc on 11/13/2023.
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

int main()
{
	int q;
	cin >> q;
	multiset<int> fi, se;
	fi.insert(0);
	se.insert(INT_MAX);
	while (q--)
	{
		char op;
		int x, y;
		cin >> op >> x >> y;

		if (op == '+')
		{
			fi.insert(x);
			se.insert(y);
		}
		else if (op == '-')
		{
			fi.erase(fi.find(x));
			se.erase(se.find(y));
		}


		auto r1 = se.begin();
		auto l2 = fi.rbegin();

		if (*r1 < *l2)
			cout << "YES" << endl;
		else cout << "NO" << endl;

	}
	return EXIT_SUCCESS;
}
