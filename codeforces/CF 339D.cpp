#include <iostream>
#include <cmath>
using namespace std;

#define ll long long
int *st;
int *arr;
ll n, m;
void build(int id, int l, int r, int depth)
{
	if (l == r)
	{
		st[id] = arr[l];
		return;
	}
	int mid = (l + r) / 2;
	build(id * 2, l, mid, depth - 1);
	build(id * 2 + 1, mid + 1, r, depth - 1);

	if (depth % 2 != 0)	
		st[id] = st[id * 2] | st[id * 2 + 1];
	else
		st[id] = st[id * 2] ^ st[id * 2 + 1];
}

void update(int id, int l, int r, int depth, int pos, int val)
{
	if (l == r && l == pos)
	{
		arr[pos] = val;
		st[id] = arr[pos];
		return;
	}
	int mid = (l + r) / 2;
	
	if (pos <= mid)
		update(id * 2, l, mid, depth - 1, pos, val);
	else
		update(id * 2 + 1, mid + 1, r, depth - 1, pos, val);
	
	if (depth % 2 != 0)
		st[id] = st[id * 2] | st[id * 2 + 1];
	else
		st[id] = st[id * 2] ^ st[id * 2 + 1];
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	int i, p, b;
	ll t = pow(2, double(n));
	arr = new int[t];
	st = new int[2 * t];
	for (i = 1; i <= t; i++)
		cin >> arr[i];
	build(1, 1, t, n);
	for (i = 1; i <= m; i++)
	{
		cin >> p >> b;
		update(1, 1, t, n, p, b);
		cout << st[1] << "\n";
	}
	return 0;
}