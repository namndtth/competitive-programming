//
// Created by nampc on 10/30/2023.
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

int main()
{
	int n, k;
	cin >> n >> k;
	string st;
	cin >> st;
	vi fwd(n + 1, 0), bwd(n + 1, 0);
	fwd[1] = bwd[n - 1] = 1;
	FOR(i, 0, n) fwd[i + 1] = (st[i] == st[i - 1] ? fwd[i] + 1 : 1);
	FORD(i, n - 1, 0) bwd[i] = (st[i] == st[i + 1] ? bwd[i + 1] + 1 : 1);

	int ans = k;
	FORN(i, 0, n - k - 1)
	{
		ans = max(ans, fwd[i + 1] + k);
		if (st[i] == st[i + k + 1])
			ans = max(ans, fwd[i + 1] + k + bwd[i + k + 1]);
	}

	cout << ans << endl;
	return EXIT_SUCCESS;
}
