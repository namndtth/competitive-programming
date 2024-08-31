//
// Created by nampc on 11/17/2023.
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

void solve(const vll& s, int& ans)
{
	const int n = s.size() - 1;
	FORRN(i, n, 1)
	{
		bool found = true;
		if (s[n] % i == 0)
		{
			ll x = s[n] / i;
			FORN(j, 1, i)
			{
				if (!binary_search(s.begin(), s.end(), x * j))
				{
					found = false;
					break;
				}
			}
			if (found)
			{
				ans = i;
				return;
			}
		}
	}
}

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		vll a(n), s(n + 1, 0);
		FOR(i, 0, n)
		{
			cin >> a[i];
			s[i + 1] = s[i] + a[i];
		}
		int ans = -1;
		solve(s, ans);
		cout << n - ans << endl;
	}
	return EXIT_SUCCESS;
}
