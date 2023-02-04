#include <iostream>
#include <climits>
using namespace std;

const int maxn = 1e5;
int k;
int main()
{
	int n, k, ans = INT_MAX;
	cin >> n >> k;
	int *cnt = new int[k];
	char ch;
	for (int i = 0; i < k; i++)
		cnt[i] = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> ch;
		cnt[(int)ch - 65]++;
	}

	for (int i = 0; i < k; i++)
	{
		ans = (ans > cnt[i] ? cnt[i] : ans);
	}
	ans *= k;
	cout << ans;
	return 0;
}