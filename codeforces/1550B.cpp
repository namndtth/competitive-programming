#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;

	int m = unique(s.begin(), s.end()) - s.begin();
	cout << n * a + max(n * b, (m / 2 + 1) * b) << endl;
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
