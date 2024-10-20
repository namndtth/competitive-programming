//
// Created by nampc on 10/1/2023.
//
#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353

long long factorial(int n)
{
	long long res = 1;
	for (int i = 2; i <= n; i++)
	{
		res *= i % MOD;
		res %= MOD;
	}
	return res;
}

void solve()
{
	string st;
	cin >> st;
	int n = (int)st.size();

	vector<int> cnt(2, 0);
	cnt[st[0] - '0']++;

	int ch;
	vector<int> f;
	for (int i = 1; i < n; i++)
	{
		ch = st[i] - '0';
		cnt[ch]++;
		if (st[i] != st[i - 1])
		{
			f.push_back(cnt[!ch]);
			cnt[!ch] = 0;
		}
	}

	f.push_back(st[n - 1] == st[n - 2] ?  cnt[ch] : 1);

	long long ops = n - f.size(), seq = 1;
	for (auto& e : f)
	{
		seq *= e;
		seq %= MOD;
	}
	seq *= factorial(ops);
	seq %= MOD;
	cout << ops << " " << seq << endl;
}

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
		solve();
	return EXIT_SUCCESS;
}
