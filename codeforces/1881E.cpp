//
// Created by nampc on 11/10/2023.
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
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		vi a(n);
		FOR(i, 0, n) cin >> a[i];
		reverse(a.begin(), a.end());

		vi dp(n + 1, 0);
		FORN(i, 1, n)
		{
			if (i <= a[i - 1]) dp[i] = dp[i - 1];
			else dp[i] = max(dp[i - 1], dp[i - a[i - 1] - 1] + a[i - 1] + 1);
		}
		cout << n - dp[n] << endl;
	}
	return EXIT_SUCCESS;
}
