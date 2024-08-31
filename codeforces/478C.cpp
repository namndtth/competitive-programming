//
// Created by nampc on 10/12/2023.
//
#include <bits/stdc++.h>
using namespace std;

int cal_remain(int& a, int& b)
{
	int x = min(a / 2, b);
	int y = min(a, b / 2);
	if (max(x, y) == x)
		a -= x * 2, b -= x;
	else b -= x * 2, a -= x;
	return max(x, y);
}
int main()
{
	int r, g, b;
	cin >> r >> g >> b;
	int ans = min(min(r, g), b);
	r -= ans, g -= ans, b -= ans;
	if (r == 0)
		swap(r, b);
	else if (g == 0)
		swap(g, b);
	int remain;
	while (r != 0 && g != 0)
	{
		remain = cal_remain(r, g);
		ans += remain;
	}
	cout << ans << endl;
	return 0;
}
