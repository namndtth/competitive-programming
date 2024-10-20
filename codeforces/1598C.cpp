#include <vector>
#include <iostream>
#include <map>
#include <algorithm>


using namespace std;
using ll = long long;;

void solve()
{
	int n;
	cin >> n;

	vector<int> a(n);
	ll s{ 0 };
	map<int, int> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		s += a[i];
		m[a[i]]++;
	}

	ll ans = 0;
	if ((s * 2) % n == 0)
	{
		s = s * 2 / n;
		for (int i = 0; i < n; i++)
		{
			int a1 = a[i];
			int a2 = s - a[i];
			if (m.count(a2)) ans += m[a2];
			if (a1 == a2) ans -= 1;
		}
	}

	cout << ans / 2 << endl;
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
