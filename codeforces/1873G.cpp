
#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	string s;
	cin >> s;
	int tot = 0;
	int mn = 1e9;
	int cur = 0;
	for (int i = 0; i < (int)s.length(); ++i) {
		if (s[i] == 'A') {
			++cur;
			++tot;
		} else {
			mn = min(mn, cur);
			cur = 0;
		}
	}
	mn = min(mn, cur);

	cout << tot - mn << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}
