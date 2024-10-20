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

struct Node
{
	ll val;
	ll lazy;
};

struct SegmentTree
{
	vector<Node> st;
	explicit SegmentTree(int n)
	{
		st.resize(4 * n);
		FOR(i, 0, 4 * n)
		{
			st[i].val = 0;
			st[i].lazy = 0;
		}
	}

	void push_down(int id)
	{
		int lazy = st[id].lazy;

		st[id * 2].val += lazy;
		st[id * 2].lazy += lazy;

		st[id * 2 + 1].val += lazy;
		st[id * 2 + 1].lazy += lazy;

		st[id].lazy = 0;
	}

	void update(int id, int l, int r, int u, int v, int val)
	{
		if (v < l || r < u)
			return;
		if (u <= l && r <= v)
		{
			st[id].val += val;
			st[id].lazy += val;
			return;
		}

		push_down(id);

		int m = (l + r) / 2;
		update(id * 2, l, m, u, v, val);
		update(id * 2 + 1, m + 1, r, u, v, val);
	}

	int get(int id, int l, int r, int pos)
	{
		if (l == r)
		{
			return st[id].val;
		}

		push_down(id);

		int m = (l + r) / 2;

		if (pos <= m)
			return get(id * 2, l, m, pos);
		else
			return get(id * 2 + 1, m + 1, r, pos);
	}
};

int main()
{
	int n, q;
	cin >> n >> q;
	vll a(n);
	FOR(i, 0, n) cin >> a[i];
	SegmentTree st(n);

	int l, r;
	FOR(i, 0, q)
	{
		cin >> l >> r;
		st.update(1, 1, n, l, r, 1);
	}

	vll cnt(n);
	FORN(i, 1, n) cnt[i - 1] = st.get(1, 1, n, i);

	sort(a.begin(), a.end());
	sort(cnt.begin(), cnt.end());

	ll ans = 0;
	FOR(i, 0, n)
	ans += a[i] * cnt[i];
	cout << ans << endl;

	return EXIT_SUCCESS;
}
