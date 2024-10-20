//
// Created by NAMND on 3/25/2023.
//
#include <bits/stdc++.h>
using namespace std;

bool isFinished(int prev, const vector<vector<int>>& a)
{
	for (int i = 1; i < a[0].size(); i++)
	{
		int current = prev;
		if (a[current][i])
			return false;
		if (!a[current][i] && !a[1 - current][i])
			prev = 1 - prev;
	}
	return true;
}
int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n;
		string string1, string2;
		cin >> n >> string1 >> string2;

		vector<vector<int>> a(2);
		for (int i = 0; i < n; i++)
		{
			a[0].push_back(string1[i] == 'B' ? 0 : 1);
			a[1].push_back(string2[i] == 'B' ? 0 : 1);
		}
		int ans{};
		if ((a[0][0] == 0 && isFinished(0, a)) || (a[1][0] == 0 && isFinished(1, a)))
			ans ^= 1;

		if (ans)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return EXIT_SUCCESS;
}