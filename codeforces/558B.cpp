#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	map<int, int> cnt;
	map<int, pair<int, int>> lr;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		cnt[v[i]]++;
		lr[v[i]] = lr.count(v[i]) == 0 ? make_pair(i, i) : make_pair(lr[v[i]].first, i);
	}
	auto comp = [](const pair<int,  int>& p1, const pair<int, int>& p2)
	{
		return p1.second < p2.second;
	};
	auto max_elem = max_element(cnt.begin(), cnt.end(), comp);

	auto minRange = lr[max_elem->first];
	for (const auto& [number, range] : lr)
	{
		if (cnt[number] == max_elem->second && range.second - range.first < minRange.second - minRange.first)
		{
			minRange = range;
		}
	}

	cout << minRange.first + 1 << " " << minRange.second + 1 << endl;

	return EXIT_SUCCESS;
}
