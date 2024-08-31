//
// Created by nampc on 12/10/2023.
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

int read()
{
	int x;
	cin >> x;
	return x;
}

int solve(const vi& a, int n)
{
	vvi dp(2010, vi(2010, -1));

	dp[0][0] = 0;

	FORN(i, 1, n)
	{
		FORN(k, 1, i)
		{
			if (dp[i - 1][k] >= 0)
				dp[i][k] = max(dp[i - 1][k], dp[i][k]);

			if (dp[i - 1][k - 1] + a[i - 1] >= 0)
				dp[i][k] = max(dp[i][k], dp[i - 1][k - 1] + a[i - 1]);

		}
	}

	FORRN(i, n, 1) if (dp[n][i] >= 0) return i;
}

int main()
{
	int n = read();

	vi a(n);
	FOR(i, 0, n) a[i] = read();

	cout << solve(a, n) << endl;

//	vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, -1));
//	dp[0][0] = 0;
//	for (int i = 0; i < n; i++){
//		for (int j = 0; j <= i; j++){
//			if (dp[i][j] >= 0){
//				dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
//				if (dp[i][j] + a[i] >= 0){
//					dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + a[i]);
//				}
//			}
//		}
//	}
//	int ans = 0;
//	for (int i = 0; i <= n; i++){
//		if (dp[n][i] >= 0){
//			ans = i;
//		}
//	}
//	FORN(i, 0, n)
//	{
//		FORN(j, 0, i)
//			cout << dp[i][j] << " ";
//		cout << endl;
//	}
//	cout << ans << endl;
	return EXIT_SUCCESS;
}
