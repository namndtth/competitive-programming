#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void print_array(const vector<ll>& a)
{
	for (auto& x : a)
		cout << x << " ";
	cout << endl;
}

ll largest_value(ll n)
{
	vector<ll> a(n), b(n);
	iota(a.begin(), a.end(), 1);
	iota(b.rbegin(), b.rend(), 1);

	vector<ll> result(n);
	transform(a.begin(), a.end(), b.begin(), result.begin(), [](const ll& x, const ll& y) { return abs(x - y); });
	return accumulate(result.begin(), result.end(), 0LL);
}

void solve()
{
	long long n, k;
	cin >> n >> k;

	if (k % 2 != 0 || k > largest_value(n))
	{
		cout << "No" << endl;
	}
	else
	{
		vector<ll> ans(n);
		iota(ans.begin(), ans.end(), 1);
		for (int i = n, j = 1; i - j >= 0; i--, j++)
		{
			if (k == 0)
				break;

			if (k >= 2 * (i - j))
			{
				swap(ans[j - 1], ans[n - j]);
				k -= 2 * (i - j);
			}
		}

		cout << "Yes" << endl;
		print_array(ans);
	}
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
