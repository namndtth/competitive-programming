//
// Created by nampc on 9/12/2023.
//
#include <bits/stdc++.h>
using namespace std;

vector<string> ans;
vector<string> a = { "4", "7" };

void backtrack(int i, string prev)
{
	if (i == 16)
		return;
	for (int j = 0; j < 2; j++)
	{
		ans.push_back(prev + a[j]);
		backtrack(i + 1, prev + a[j]);
	}
}
int main()
{
	backtrack(0, "");
	set<long long> s;
	int sz = (int)ans.size();
	for (int i = 0; i < sz; i++)
	{
		s.insert(stoll(ans[i]));
	}
	int l, r;
	cin >> l >> r;
	long long tot = 0;
	auto it = s.lower_bound(r);
	tot -= (*it - r) * (*it);
	for (long long i = l; i <= r; i++)
	{
		long long v = *s.lower_bound(i);
		tot += v * (v - i + 1);
		i = v;
	}
	cout << tot << endl;
	return EXIT_SUCCESS;
}
