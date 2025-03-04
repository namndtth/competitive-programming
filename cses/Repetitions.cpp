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
	string dna;
	cin >> dna;

	int ans = 1;
	int cnt = 1;
	FOR(i, 1, dna.size())
	{
		if (dna[i] == dna[i - 1])
		{
			cnt++;
			ans = max(ans, cnt);
		}
		else cnt = 1;
	}
	cout << ans << endl;
	return EXIT_SUCCESS;
}
