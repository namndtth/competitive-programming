//
// Created by nampc on 11/4/2023.
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

class Solution
{
	int memo[35][35][35];
public:
	int minCost(const vi& stones, const vi& cost, int L, int R, int piles, int K)
	{
		if (L == R && piles == 1) return 0;

		if (L == R) return INT_MAX;

		if (memo[L][R][piles] != -1)
			return memo[L][R][piles];

		if (piles == 1)
		{
			int c = minCost(stones, cost, L, R, K, K);
			if (c == INT_MAX)
				memo[L][R][piles] = INT_MAX;
			else
				memo[L][R][piles] = c + cost[R + 1] - cost[L];
			return memo[L][R][piles];
		}

		int res = INT_MAX;
		FOR(i, L, R)
		{
			int l = minCost(stones, cost, L, i, piles - 1, K);
			int r = minCost(stones, cost, i + 1, R, 1, K);
			if (l != INT_MAX && r != INT_MAX)
			{
				res = min(res, l + r);
				memo[L][R][piles] = res;
			} else memo[L][R][piles] = INT_MAX;
		}
		return memo[L][R][piles];
	}
	int mergeStones(vector<int>& stones, int K)
	{
		const int n = static_cast<int>(stones.size());
		if (n == 1)
			return 0;
		memset(memo, -1, sizeof memo);
		vi cost(n + 1, 0);
		FOR(i, 0, n) cost[i + 1] = cost[i] + stones[i];
		minCost(stones, cost, 0, n - 1, 1, K);
		if (memo[0][n - 1][1] == INT_MAX)
			return -1;
		return memo[0][n - 1][1];
	}
};

int main()
{
	int n, k;
	cin >> n >> k;
	vi nums(n);
	FOR(i, 0, n) cin >> nums[i];
	Solution sol;
	cout << sol.mergeStones(nums, k) << endl;
	return EXIT_SUCCESS;
}
