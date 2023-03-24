#include <bits/stdc++.h>
using namespace std;

void find_answer(int n, int k)
{
	vector<int> ans(k);
	if ((n - k + 1) % 2 == 1 && (n - k + 1) > 0)
	{
		fill(ans.begin(), ans.end(), 1);
		ans[k - 1] = n - k + 1;
	}
	else if ((n - 2 * k + 2) % 2 == 0 && (n - 2 * k + 2) > 0)
	{
		fill(ans.begin(), ans.end(), 2);
		ans[k - 1] = n - 2 * k + 2;
	}
	else
	{
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for (auto e: ans)
		cout << e << " ";
	cout << endl;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		if (k > n)
			cout << "NO\n";
		else if (n == 1) cout << "YES\n" << n << endl;
		else find_answer(n, k);
	}
	return 0;
}
