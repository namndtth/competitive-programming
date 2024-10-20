#include <bits/stdc++.h>

using namespace std;

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int l, r, L, R;
		cin >> l >> r;
		cin >> L >> R;

		if (l > L)
		{
			swap(l, L);
			swap(r, R);
		}

		if (r < L || R < l)
			cout << 1 << endl;
		else if (l == L)
		{
			if (r == R)
				cout << r - l << endl;
			else
				cout << min(r, R) - l + 1 << endl;
		}
		else if (l < L)
		{
			if (r == R)
				cout << R - L + 1 << endl;
			else
				cout << min(r, R) - L + 2 << endl;
		}
	}
	return EXIT_SUCCESS;
}
