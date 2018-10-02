#include <iostream>
using namespace std;

int main()
{
	int n, a, b, i, j;
	int c[20];
	cin >> n >> a >> b;
	int val = (a == 0 ? a : b);
	for (i = 0; i < n; i++)
		cin >> c[i];
	i = 0;
	j = n - 1;
	int res = 0;
	while (i <= j)
	{
		if (c[i] != 2 && c[j] != 2 && c[i] != c[j])
		{
			cout << -1;
			return 0;
		}
		else
			if (c[i] == 2 && c[j] != 2)
			{
				c[i] = c[j];
				if (c[j] == 0)
					res += a;
				else
					res += b;
			}
			else
				if (c[i] != 2 && c[j] == 2)
				{
					c[j] = c[i];
					if (c[i] == 0)
						res += a;
					else
						res += b;
				}
				else
					if (c[i] == 2 && c[j] == 2 && i != j)
					{
						int t = (a < b ? a : b);
						res += 2 * t;
					}
					else
						if (c[i] == 2 && c[j] == 2 && i == j)
							res += (a < b ? a : b);					
		i++, j--;
	}
	cout << res;
	return 0;
}