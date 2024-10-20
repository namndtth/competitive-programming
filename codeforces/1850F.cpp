#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	cin >> tc;

	while (tc--)
	{
		int n;
		cin >> n;
		vector<int> a(n);

		map<int, int> freq;
		for (auto& e : a)
		{
			cin >> e;
			if (e <= n)
			{
				freq[e]++;
			}
		}

		int ans = 0;
		map<int, int> cnt;
		for (auto& e : freq)
		{
			int hop = e.first;
			int frogs = e.second;
			while (hop <= n)
			{
				cnt[hop] += frogs;
				ans = max(ans, cnt[hop]);

				hop += e.first;
			}
		}
		cout << ans << endl;
	}
	return EXIT_SUCCESS;
}
