//
// Created by NAMND on 4/4/2023.
//
#include <bits/stdc++.h>
using namespace std;

int needed(string number, string power_of_two)
{
	int same = 0;
	int i = 0, j = 0;
	while (i < power_of_two.size() && j < number.size())
	{
		if (power_of_two[i] == number[j])
		{
			same++;
			i++, j++;
		}
		else j++;

	}
	return power_of_two.size() + number.size() - 2 * same;
}

void solve()
{
	string number;
	cin >> number;
	vector<string> power_of_two;
	for (int i = 0; i < 64; ++i)
	{
		power_of_two.push_back(to_string(1ULL << i));
	}

	int ans = INT_MAX;
	for (const auto& e:power_of_two)
		ans = min(ans, needed(number, e));
	cout << ans << endl;
}

int main()
{
	int t; cin >> t;
	while (t--)
		solve();
	return EXIT_SUCCESS;
}