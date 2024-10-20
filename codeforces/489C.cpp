//
// Created by nampc on 9/4/2023.
//
#include <bits/stdc++.h>
using namespace std;

bool can(int m, int s)
{
	return (s >= 0 && s <= m * 9);
}

// Build number from digit to digit
// Careful to handle case leading zero
void minimize(int m, int s)
{
	string ans;
	for (int i = 0; i < m; i++)
	{
		for (int d = 0; d < 10; d++)
			if ((i > 0 || d > 0 || (m == 1 && s == 0)) && can(m - i - 1, s - d))
			{
				ans += char('0' + d);
				s -= d;
				break;
			}
	}
	cout << ans << " ";
}

void maximize(int m, int s)
{
	string ans;
	for (int i = 0; i < m; i++)
	{
		for (int d = 9; d >= 0; d--)
			if (can(m - i - 1, s - d))
			{
				ans += char('0' + d);
				s -= d;
				break;
			}
	}
	cout << ans << endl;
}

int main()
{
	int m, s;
	cin >> m >> s;
	if ((s == 0 && m != 1) || m * 9 < s)
		cout << "-1 -1" << endl;
	else
	{
		minimize(m, s);
		maximize(m, s);
	}
	return EXIT_SUCCESS;
}
