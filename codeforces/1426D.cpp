//
// Created by nampc on 10/3/2023.
//
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

int main()
{
	int n;
	cin >> n;
	vll a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int ans = 0;
	set<ll> s;
	ll res = 0;
	for (int i = 0; i < n; i++)
	{
		res += a[i];
		if (res == 0 || s.count(res))
		{
			s.clear();
			res = a[i];
			s.insert(res);
			ans++;
		}
		else
			s.insert(res);
	}
	cout << ans << endl;
	return EXIT_SUCCESS;
}
