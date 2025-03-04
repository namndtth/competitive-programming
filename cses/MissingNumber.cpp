//
// Created by nampc on 11/8/2023.
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
	ll n;
	cin >> n;
	ll sum = 0, x;
	FOR(i, 0, n - 1)
	{
		cin >> x;
		sum += x;
	}
	cout << n * ( n + 1) / 2 - sum << endl;
	return EXIT_SUCCESS;
}
