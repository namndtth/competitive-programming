#include <iostream>
using namespace std;
int analysis(int n, int k)
{
	int i, res = 0;
	for (i = 1; i <= 4; i++)
	{
		if (n > 0)
		{
			res++;
			n -= i * k * 0.1;
		}
	}
	return res;
}
int main()
{
	int i = 1, n, res = 0;
	cin >> n;
	int k = 10;
	while (n > k)
	{
		res += 4;
		n -= k;
		k *= 10;
	}
	res += analysis(n, k);
	cout << res;
	return 0;
}
