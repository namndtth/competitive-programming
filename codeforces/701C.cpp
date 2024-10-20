//
// Created by nampc on 9/7/2023.
//
#include <bits/stdc++.h>
using namespace std;

// Using two pointers
// Iterate through every character in string st
// Second pointer move behind the first one
// If current character is duplicate, we will increase 2nd iterator by 1
// then recalculate number of characters needed to include all different characters
int main()
{
	int n;
	cin >> n;
	string st;
	cin >> st;
	map<int, int> f;
	int begin = 0, total = 0;
	vector<int> ans(500, INT_MAX);
	for (int k = 0; k < n; k++)
	{
		if (!f[st[k]]) total++;
		f[st[k]]++;
		while (begin < k && f[st[begin]] > 1)
		{
			f[st[begin]]--;
			begin++;
		}
		ans[total] = min(ans[total], k - begin + 1);
	}
	cout << ans[total] << endl;
	return EXIT_SUCCESS;
}
