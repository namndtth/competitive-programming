#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n;
	cin >> n;

	vector<int> a(n);
	for (auto& x : a)
		cin >> x;

	std::sort(a.begin(), a.end());

	long long ans = LONG_LONG_MIN;
	for (int i = 0; i <= 5; i++)
	{
		long long product = 1;
		for (int x = 0; x < i; x++)
			product *= a[x];
		for (int y = n + i - 5; y < n; y++)
			product *= a[y];
		ans = max(ans, product);
	}
	cout << ans << endl;
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
