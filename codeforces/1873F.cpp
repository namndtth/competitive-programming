//
// Created by nampc on 11/3/2023.
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

struct Solution
{
	vi length, sum, a, h;
	int n, k;

	void input()
	{
		cin >> n >> k;

		length.assign(n + 1, 0);
		sum.assign(n + 1, 0);
		a.assign(n, 0);
		h.assign(n, 0);

		sum[0] = 0;
		FOR(i, 0, n)
		{
			cin >> a[i];
			sum[i + 1] = sum[i] + a[i];
		}

		FOR(i, 0, n) cin >> h[i];
		length[n - 1] = 1;
		FORRN(i, n - 2, 0)
		{
			if (h[i] % h[i + 1] == 0)
				length[i] = length[i + 1] + 1;
			else
				length[i] = 1;
		}
	}

	void solve()
	{
		int l = 1, r = n;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (isOk(mid))
			{
				l = mid + 1;
			}
			else r = mid - 1;
		}
		cout << r << endl;
	}

	void solve_multiple()
	{
		int tc; cin >> tc;
		while (tc--)
		{
			input();
			solve();
		}
	}

	bool isOk(int dist)
	{
		bool found = false;
		FOR(i, 0, n - dist + 1)
		{
			if (length[i] < dist) continue;
			if (sum[i + dist] - sum[i] <= k)
			{
				found = true;
				break;
			}
		}
		return found;
	}
};

int main()
{
	Solution sol;
	sol.solve_multiple();
	return EXIT_SUCCESS;
}
