//
// Created by NAMND on 3/25/2023.
//

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		vector<pair<int, int>> subtraction;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (i != 0)
				subtraction.emplace_back(a[i] - a[i - 1], i);
		}
		if (n == 1)
		{
			cout << 1 << endl;
			continue;
		}
		sort(subtraction.begin(), subtraction.end(),
			[](pair<int, int> a, pair<int, int> b)
			{
				return a.first > b.first;
			});

		vector<int> ans;
		pair<int, int> back = subtraction.back();
		subtraction.pop_back();
		for (int i = n; i > 0; i--)
		{
			if (back.first > 0)
			{
				ans.push_back(1);
				continue;
			}
			back.first += i;
			ans.push_back(back.second + 1);
			if (back.first > 0 && !subtraction.empty())
			{
				back = subtraction.back();
				subtraction.pop_back();
			}

		}
		std::reverse(ans.begin(), ans.end());
		for (const auto& e: ans)
			cout << e << " ";
		cout << endl;
	}
	return EXIT_SUCCESS;
}