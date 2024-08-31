//
// Created by nampc on 10/4/2023.
//
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tc; cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		string bin;
		cin >> bin;
		vector<int> x(n + 1, 0);
		int x0 = 0, x1 = 0;
		for (int i = 0; i < n; i++)
		{
			x[i + 1] = x[i] ^ a[i];
			bin[i] == '0' ? x0 ^= a[i] : x1 ^= a[i];
		}
		int q;
		cin >> q;
		int tp, l, r, g;
		for (int i = 0; i < q; i++)
		{
			cin >> tp;
			if (tp == 1)
			{
				cin >> l >> r;
				int xor_lr = x[r] ^ x[l - 1];
				x0 ^= xor_lr;
				x1 ^= xor_lr;
			}
			else
			{
				cin >> g;
				cout << (g == 0 ? x0 : x1) << " ";
			}
		}
		cout << endl;
	}
	return EXIT_SUCCESS;
}
