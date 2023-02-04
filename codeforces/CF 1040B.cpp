#include <iostream>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int i;
	int pos = -1;
	bool found = true;
	int res = 0;
	if (k == 0)
	{
		res = n;
		pos = 1;
	}
	else
		for (i = 1; i <= k; i++)
		{
			res = 0;
			int t = n;
			t -= i;
			pos = i;
			res++;
			while (t > 0)
			{
				if (t - 2*k-1 < 0)
					break;
				else
				{
					t -= 2 * k + 1;
					res++;
					if (t < k)
					{
						found = false;
						break;
					}
				}
			}
			if (found)
				break;
		}
	cout << res << "\n";
	cout << pos << " ";
	while (pos < n)
	{
		pos += 2 * k + 1;
		if (pos > n)
			break;
		else
			cout << pos << " ";
	}
	return 0;
}