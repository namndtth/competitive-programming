#include <bits/stdc++.h>

using namespace std;

int main()
{
	map<pair<int, int>, int> check_duplicate;
	map<int, int> fx;
	map<int, int> fy;
	int n;
	cin >> n;
	int x, y;
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		fx[x]++;
		fy[y]++;
		check_duplicate[{x, y}]++;

		if (fx[x] >= 2)
			ans += fx[x] - 1;
		if (fy[y] >= 2)
			ans += fy[y] - 1;
		if (check_duplicate[{x, y}])
			ans -= check_duplicate[{x, y}] - 1;
	}
	cout << ans << endl;
	return EXIT_SUCCESS;
}
