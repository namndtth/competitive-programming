#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> calculate_accumulation(const vector<int>& a)
{
	vector<ll> results(a.size());
	for (int i = 0; i < a.size(); ++i)
	{
		if (i != 0)
			results[i] = a[i] + results[i - 1];
		else
			results[i] = a[i];
	}
	return results;
}
int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	vector<ll> acc(n), asc_acc(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	acc = calculate_accumulation(a);

	sort(a.begin(), a.end());

	asc_acc = calculate_accumulation(a);

	int m;
	cin >> m;
	int type, l, r;

	for (int i = 0; i < m; ++i)
	{
		cin >> type >> l >> r;
		l--, r--;
		if (type == 1)
		{
			if (l == 0) cout << acc[r] << endl;
			else
				cout << acc[r] - acc[l - 1] << endl;
		}
		else
		{
			if (l == 0) cout << asc_acc[r] << endl;
			else
				cout << asc_acc[r] - asc_acc[l - 1] << endl;
		}
	}
	return EXIT_SUCCESS;
}