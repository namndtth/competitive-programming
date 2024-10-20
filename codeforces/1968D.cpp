#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll score(const vector<ll>& p, const vector<ll>& a, int pos, int k)
{
	vector visited(p.size(), false);

	ll sum = 0, ans = 0;
	while (!visited[pos] && k > 0)
	{
		visited[pos] = true;
		sum += a[pos];
		k--;

		ans = max(ans, sum + k * a[pos]);

		pos = p[pos];
	}

	return ans;
}

void solve()
{
	int n, k, pb, ps;
	cin >> n >> k >> pb >> ps;

	vector<ll> p(n);
	for (auto& x : p)
	{
		cin >> x;
		--x;
	}

	vector<ll> a(n);
	for (auto& x : a)
	{
		cin >> x;
		--x;
	}

	ll bodyaScore = score(p, a, --pb, k);
	ll sashaScore = score(p, a, --ps, k);

	if (bodyaScore > sashaScore) cout << "Bodya" << endl;
	else if (bodyaScore < sashaScore) cout << "Sasha" << endl;
	else cout << "Draw" << endl;
}

int main()
{
	int tc;
	cin >> tc;

	while (tc--)
	{
		solve();
	}

	return EXIT_SUCCESS;
}
