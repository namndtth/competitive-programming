#include <bits/stdc++.h>

using namespace std;

int main()
{
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	int x3{ x1 }, y3{ y2 }, x4{ x2 }, y4{ y1 };

	int dx = abs(x2 - x1), dy = abs(y2 - y1);
	if (dx != dy && dx != 0 & dy != 0)
	{
		cout << -1 << endl;
		return EXIT_SUCCESS;
	}
	else if (dx == 0)
	{
		x3 += dy;
		x4 += dy;
	}
	else if (dy == 0)
	{
		y3 += dx;
		y4 += dx;
	}

	cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
	return EXIT_SUCCESS;
}
