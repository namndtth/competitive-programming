//
// Created by nampc on 11/5/2023.
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

class SolutionMemo
{
	vvi memo, pal;
public:
	int count(const string& s, int L, int R)
	{
		if (L > R)
			return 0;

		if (L == R)
			return pal[L][R] = memo[L][R] = 1;

		if (L + 1 == R)
		{
			if (s[L] == s[R])
			{
				pal[L][R] = 1;
				memo[L][R] = 3;
			}
			else
			{
				pal[L][R] = 0;
				memo[L][R] = 2;
			}
			return memo[L][R];
		}

		if (memo[L][R] != -1) return memo[L][R];

		int res = count(s, L + 1, R) + count(s, L, R - 1) - count(s, L + 1, R - 1);
		if (s[L] == s[R] && pal[L + 1][R - 1])
		{
			pal[L][R] = 1;
			res++;
		}
		memo[L][R] = res;
		return memo[L][R];
	}

	int countSubstrings(const string& s)
	{
		const int n = static_cast<int>(s.size());
		memo.assign(n + 1, vi(n + 1, -1));
		pal.assign(n + 1, vi(n + 1, 0));
		return count(s, 0, n - 1);
	}
};

class Solution
{
	vvi dp;
	vector<vector<bool>> isPal;
public:
	int countSubstrings(const string& s)
	{
		const int n = static_cast<int>(s.size());
		dp.assign(n + 1, vi(n + 1));
		isPal.assign(n + 1, vector<bool>(n + 1, false));

		FOR(i, 0, n) isPal[i][i] = dp[i][i] = 1;
		FOR(i, 0, n - 1)
		{
			if (s[i] == s[i + 1])
			{
				dp[i][i + 1] = 3;
				isPal[i][i + 1] = true;
			}
			else
			{
				dp[i][i + 1] = 2;
				isPal[i][i + 1] = false;
			}
		}

		FORR(i, n - 2, 0)
		{
			FOR(j, i + 2, n)
			{
				if (s[i] == s[j] && isPal[i + 1][j - 1])
				{
					dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + 1;
					isPal[i][j] = true;
				}
				else
				{
					dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
					isPal[i][j] = false;
				}
			}
		}
		return dp[0][n - 1];
	}
};

int main()
{
	string s;
	cin >> s;
	Solution sol;
	cout << sol.countSubstrings(s) << endl;
	return EXIT_SUCCESS;
}
