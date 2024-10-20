#include <bits/stdc++.h>

using namespace std;

void solve()
{
	string a, b;
	cin >> a >> b;

	int n = a.size();
	int pos = mismatch(a.begin(), a.end(), b.begin()).first - a.begin();

	if (a[pos] > b[pos])
	{
		swap(a[pos], b[pos]);
	}

	for (pos = pos + 1; pos < n; pos++)
	{
		if (a[pos] < b[pos])
			swap(a[pos], b[pos]);
	}

	cout << a << endl << b << endl;
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
