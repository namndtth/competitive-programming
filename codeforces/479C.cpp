//
// Created by nampc on 10/12/2023.
//

#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

int main()
{
	int n;
	cin >> n;
	int a, b;
	vector<pii> vp;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		vp.emplace_back(a, b);
	}

	sort(vp.begin(), vp.end());

	int best = -1;
	for (int i = 0; i < n; i++)
	{
		if (best <= vp[i].second)
			best = vp[i].second;
		else
			best = vp[i].first;
	}
	cout << best << endl;
	return EXIT_SUCCESS;
}
