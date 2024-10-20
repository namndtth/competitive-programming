#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin >> n;

	vector<int> a(n), b(n);
	for (auto& e : a)
		cin >> e;

	for (auto& e : b)
		cin >> e;

	int x = 0, y = 0, neg = 0, pos = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > b[i])
			x += a[i];
		else if (a[i] < b[i])
			y += b[i];
		else
		{
			neg += (a[i] < 0);
			pos += (a[i] > 0);
		}
	}

	int ans = INT32_MIN;
	for (int i = -neg; i <= pos; i++)
		ans = max(ans, min(x + i, y + pos - neg - i));

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
