#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ll n, k, x;
	cin >> n >> k >> x;

	vector<ll> a(n);
	for (auto& item : a)
		cin >> item;

	sort(a.begin(), a.end());

	vector<ll> b;
	for (int i = 1; i < n; i++)
		if (a[i] - a[i - 1] > x)
			b.push_back((a[i] - a[i - 1] - 1) / x);
	sort(b.begin(), b.end());

	int ans = { 1 };
	ll sum{ 0 };
	for (int i = 0; i < b.size(); i++)
	{
		if (sum + b[i] > k)
		{
			ans += b.size() - i;
			break;
		}
		sum += b[i];
	}
	cout << ans << endl;
	return EXIT_SUCCESS;
}
