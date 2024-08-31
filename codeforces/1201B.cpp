//
// Created by nampc on 10/22/2023.
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

int main()
{
	int n;
	cin >> n;
	ll mx = INT_MIN;
	vector<ll> a(n);
	vector<ll> sum(n + 1, 0);
	FOR(i, 0, n)
	{
		cin >> a[i];
		mx = max(mx, a[i]);
		sum[i + 1] = sum[i] + a[i];
	}

	bool found = false;
	if (sum[n] % 2 == 0 && mx <= sum[n] - mx)
		found = true;
	cout << (found ? "YES\n" : "NO\n");
	return EXIT_SUCCESS;
}
