#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n_choose_2(int n)
{
	return n * (n - 1) / 2;
}

ll cal_min(int n, int m)
{

	return 1LL * n_choose_2(n / m) * (m + n % m);
}

ll cal_max(int n, int m)
{
	return n_choose_2(n - m + 1);
}

int main()
{
	int n, m;
	cin >> n >> m;

	cout << cal_min(n, m) << " " << cal_max(n, m) << endl;
	return EXIT_SUCCESS;
}
