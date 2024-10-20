#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int num_ops_make_zero(int x)
{
	int result = 0;
	while (x)
	{
		x /= 3;
		result++;
	}

	return result;
}
vector<ll> precompute()
{
	vector<ll> result = { 0 };
	for (int i = 1; i <= 2e5 + 10; i++)
	{
		result.push_back(num_ops_make_zero(i));
	}

	return result;
}


int main()
{
	vector<ll> num_ops = precompute();
	vector<ll> num_ops_sum(num_ops.size());

	partial_sum(num_ops.begin(), num_ops.end(), num_ops_sum.begin());

	int tc;
	cin >> tc;

	while (tc--)
	{
		int l, r;
		cin >> l >> r;
		ll ans = num_ops[l] * 2;
		cout << ans + num_ops_sum[r] - num_ops_sum[l] << endl;
	}

	return EXIT_SUCCESS;
}
