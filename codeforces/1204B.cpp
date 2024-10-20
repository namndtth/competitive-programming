#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, l, r;
	cin >> n >> l >> r;

	int mn = n - l, mx = (n - r) * (1 << (r - 1));
	for (int i = 0; i < l; i++)
		mn += (1 << i);

	for (int i = 0; i < r; i++)
		mx += (1 << i);

	cout << mn << " " << mx << endl;
	return EXIT_SUCCESS;
}

