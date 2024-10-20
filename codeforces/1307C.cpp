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
	vll cnt(26, 0);
	vector<vll> cnt2d(26, vll(26));

	string st;
	cin >> st;

	const int n = st.size();

	ll ans = LLONG_MIN;
	FOR(i, 0, n)
	{
		int ch = st[i] - 'a';
		cnt[ch]++;
		cnt2d[ch][ch] = max(cnt[ch], cnt[ch] * (cnt[ch] - 1) / 2);
		FOR(j, 0, 26)
		{
			if (ch != j) cnt2d[ch][j] += cnt[j];
			ans = max(ans, cnt2d[ch][j]);
		}
	}
	cout << ans << endl;
	return EXIT_SUCCESS;
}
