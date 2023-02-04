#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
using namespace std;

typedef long long ll;
int arr[1000000 + 10], tree[1000000 + 10], n;
map <int, int> cnt, knt;

void update(int idx, int val)
{
	for (; idx <= n; idx += (idx&-idx)) tree[idx] += val;
}

ll query(int idx)
{
	ll val = 0;
	for (; idx>0; idx -= (idx&-idx)) val += tree[idx];
	return val;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);

	for (int i = n; i >= 1; i--)
	{
		int k = ++cnt[arr[i]];
		update(k, 1);
	}

	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int k = cnt[arr[i]]--;
		update(k, -1);
		k = ++knt[arr[i]];
		ans += query(k - 1);
	}

	cout << ans << endl;
	return 0;
}