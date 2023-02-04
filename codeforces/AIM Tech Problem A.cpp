#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL), cout.tie(NULL);
	int n, m, i, j;
	cin >> n >> m;
	int **arr = new int*[n + 1];
	for (i = 0; i <= n; i++)
		arr[i] = new int[m + 1];

	bool flag = false;
	pair <int, int> f, s;
	char x;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
		{
			cin >> x;
			arr[i][j] = (int)x;
			if (!flag)
				if (arr[i][j] == (int)'B')
				{
					f.first = i;
					f.second = j;
					flag = true;
				}
		}
	s.first = f.first;
	s.second = f.second;
	while (s.first <= n)
	{
		if (arr[s.first][f.second] == (int)'B')
			s.first++;
		else
			break;
	}
	while (s.second <= m)
	{
		if (arr[f.first][s.second] == (int)'B')
			s.second++;
		else
			break;
	}
	cout << (f.first + s.first) / 2 << " " << (f.second + s.second) / 2;
	return 0;
}