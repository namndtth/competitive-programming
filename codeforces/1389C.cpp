//
// Created by nampc on 10/29/2023.
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
using vll = vector<ll>;
using vii = vector<pair<int, int>>;

int num_possible(vi a, vi b)
{
	int res = 0;
	int val = a.front();
	swap(a, b);
	while (true)
	{
		res++;
		auto it = upper_bound(a.begin(), a.end(), val);
		if (it == a.end())
			break;

		val = *it;
		swap(a, b);
	}
	return res % 2 == 0 ? res : res - 1;
}

int main()
{
	int tc; cin >> tc;
	while (tc--)
	{
		string st;
		cin >> st;

		int n = (int)st.size();
		vvi cnt(26, vector<int>());

		FOR(i, 0, n) cnt[st[i] - '0'].push_back(i);

		int ans = INT_MIN;
		FOR(i, 0, 10)
		{
			if (cnt[i].empty()) continue;
			FOR(j, 0, 10)
			{
				if (cnt[j].empty()) continue;
				if (i == j)
					ans = max(ans, (int)cnt[i].size());
				else
					ans = max(ans, num_possible(cnt[i], cnt[j]));
			}
		}
		cout << n - ans << endl;
	}
	return 0;
}
