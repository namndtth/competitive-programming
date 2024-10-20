#include <bits/stdc++.h>
using namespace std;

void solve()
{
	string X, Y;
	cin >> X >> Y;

	int n = X.size(), m = Y.size();
	int ans = n + m;
	for (int i = 0; i < m; i++)
	{
		int j = i;
		for (auto& c : X)
			if (j < m && c == Y[j]) j++;
		ans = min(ans, n + m - (j - i));
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

