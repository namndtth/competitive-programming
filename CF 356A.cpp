#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
struct Element
{
	int left;
	int right;
	int value;
	Element(int l, int r, int v)
	{
		left = l;
		right = r;
		value = v;
	}
};

void update(int *res, int *filled, int l, int r, int x)
{
	int i;
	for (i = l; i <= r; i++)
	{
		if (i == x)
			continue;
		else
			if (filled[i] == 0)
			{
				res[i] = x;
				filled[i] = 1;
			}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL), cout.tie(NULL);
	vector<Element> arr;
	int n, m, i;
	cin >> n >> m;
	int *res = new int[n + 1];
	int *filled = new int[n + 1];
	for (i = 1; i <= n; i++)
		filled[i] = 0;
	for (i = 0; i < m; i++)
	{
		int l, r, v;
		cin >> l >> r >> v;
		arr.push_back(Element(l, r, v));
	}

	for (i = 0; i < m; i++)
	{
		update(res, filled, arr[i].left, arr[i].right, arr[i].value);
	}
	res[arr[m - 1].value] = 0;
	for (i = 1; i <= n; i++)
		cout << res[i] << " ";
	return 0;
}