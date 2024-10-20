//
// Created by nampc on 10/15/2023.
//
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MAX = 1e6 + 50;

vector<bool> primes(MAX, true);

void cal_primes()
{
	for (ll i = 2; i * i < MAX; i++)
	{
		if (primes[i])
		{
			for (ll j = i * i; j < MAX; j += i)
				primes[j] = false;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	cal_primes();

	ll x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (x == 1)
			cout << "NO" << endl;
		else
		{
			long long sr = sqrt(x);
			cout << ((sr * sr == x && primes[sr]) ? "YES" : "NO") << endl;
		}
	}
	return EXIT_SUCCESS;
}
