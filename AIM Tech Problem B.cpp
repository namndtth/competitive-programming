#include <iostream>
using namespace std;

int calc(int x)
{
	int s = 0;
	while (x > 0)
	{
		s += x % 10;
		x /= 10;
	}
	return s;
}
int main()
{
	int n, m;
	cin >> n >> m;
	cout << calc(n);
	return 0;
}