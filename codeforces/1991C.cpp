#include <bits/stdc++.h>
using namespace std;

void print_ans(const vector<int>& v)
{
	vector<int> ans;
	int sum = 0;
	for (int i = 0; i < v.size() - 1; i++)
	{
		int current = (v[i] + v[i + 1] - 2 * sum) / 2;
		sum += current;
		ans.push_back(current);
	}
	ans.push_back(v.back() - sum);

	if (ans.size() > 40)
	{
		cout << -1 << endl;
		return;
	}

	cout << ans.size() << endl;
	for (auto& x : ans)
		cout << x << " ";
	cout << endl;
}

void solve()
{
	int n;
	cin >> n;

	vector<int> a(n), odds, evens;
	for (auto& x : a)
	{
		cin >> x;
		if (x % 2 == 0) evens.push_back(x);
		else odds.push_back(x);
	}

	if (!odds.empty() && !evens.empty())
	{
		cout << -1 << endl;
		return;
	}

	if (!odds.empty())
	{
		sort(odds.begin(), odds.end());
		auto last = unique(odds.begin(), odds.end());
		odds.erase(last, odds.end());

		print_ans(odds);
	}
	else
	{
		sort(evens.begin(), evens.end());
		auto last = unique(evens.begin(), evens.end());
		evens.erase(last, evens.end());

		print_ans(evens);
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
