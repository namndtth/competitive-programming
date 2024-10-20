#include <bits/stdc++.h>
using namespace std;

using ll = long long;
pair<ll, ll> make_segment(const vector<int>& monster)
{
	ll start{ 0 };
	for (int i = 0; i < monster.size(); ++i) start = max(start, monster[i] + 1LL - i);

	ll end = start + monster.size();
	return make_pair(start, end);
}

void solve()
{
	int n;
	cin >> n;

	vector<pair<ll, ll>> segments;
	vector<vector<int>> monsterInCaves(n);
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;

		monsterInCaves[i].resize(k);

		for (int j = 0; j < k; j++)
			cin >> monsterInCaves[i][j];

		segments.push_back(make_segment(monsterInCaves[i]));
	}

	sort(segments.begin(), segments.end());

	for (int i = segments.size() - 2; i >= 0; --i)
	{
		if (segments[i].second < segments[i + 1].first)
		{
			segments[i].first += segments[i + 1].first - segments[i].second;
			segments[i].second = segments[i + 1].first;
		}
	}

	cout << segments.front().first << endl;
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
