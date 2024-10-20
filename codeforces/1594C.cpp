#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n;
	cin >> n;

	char c;
	cin >> c;

	string s;
	cin >> s;
	vector<int> ans;
	bool ok{ true };
	for (int i{ 0 }; i < n; i++)
		ok &= (s[i] == c);

	if (!ok)
	{
		for (int x = 1; x <= n; x++)
		{
			ok = true;
			for (int j = x; j <= n; j += x)
				ok &= (s[j - 1] == c);

			if (ok)
			{
				ans.push_back(x);
				break;
			}
		}

		if (!ok)
		{
			ans.push_back(n);
			ans.push_back(n - 1);
		}
	}

	cout << ans.size() << endl;
	for (int x : ans)
	{
		cout << x << ' ';
	}
	cout << "\n";
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
