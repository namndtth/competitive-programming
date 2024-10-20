#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin >> n;

	int m = n * (n - 1) / 2;
	vector<int> b(m);

	map<int, int> freq;
	for (auto& e : b)
	{
		cin >> e;
		freq[e]++;
	}

	int tmp = n - 1;
	vector<int> a;
	for (auto& [num, f] : freq)
	{
		while (f > 0)
		{
			a.push_back(num);
			f -= tmp;
			tmp--;
		}
	}

	while (a.size() < n)
	{
		a.push_back(a.back());
	}

	for (auto& e : a)
		cout << e << " ";

	cout << endl;
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
