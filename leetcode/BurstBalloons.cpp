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
public:
	int maxCoins(vector<int>& nums)
	{
		const int n = static_cast<int>(nums.size());
		vvi dp(n, vi(n));
		FORR(L, n, 0)
		{
			FOR(R, L, n)
			{
				FORN(i, L, R)
				{
					int coins = (L <= 0 ? 1 : nums[L - 1]) * nums[i] * (R == n - 1 ? 1 : nums[R + 1]);
					coins += (i > 0 ? dp[L][i - 1] : 0) + (i < n - 1 ? dp[i + 1][R] : 0);
					dp[L][R] = max(dp[L][R], coins);
				}
			}
		}
		return dp[0][n - 1];
	}
};

int main()
{
	int n;
	cin >> n;
	vi nums(n);
	FOR(i, 0, n) cin >> nums[i];
	Solution sol;
	cout << sol.maxCoins(nums) << endl;
	return EXIT_SUCCESS;
}
