#include <iostream>
#include <cstring>
using namespace std;

int a[45001];
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
	int i, n;
	cin >> n;
	if (n <= 2)
	{
		cout << "No";
		return 0;
	}
	else
	{
		memset(a, 0, sizeof a);
		for (i = 1; i <= n; i++)
			a[i] = a[i - 1] + i;
		for (i = 1; i <= n; i++)
			if (gcd(a[i], a[n] - a[i]) > 1)
			{
				cout << "Yes\n";
				int k = i;
				cout << k << " ";
				for (i = 1; i <= k; i++)
					cout << i << " ";

				cout << "\n";
				cout << n - k << " ";
				for (i = k + 1; i <= n; i++)
					cout << i << " ";
				break;
			}
	}
	return 0;
}

