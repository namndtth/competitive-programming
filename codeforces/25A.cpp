#include <bits/stdc++.h>
using namespace std;

int main()
{
	int odd_counter{}, even_counter{};
	int last_odd{}, last_even {};
	int n, x;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		if (x & 1)
		{
			even_counter++;
			last_even = i;
		}
		else
		{
			odd_counter++;
			last_odd = i;
		}
	}
	if (even_counter > odd_counter)
		cout << ++last_odd;
	else
		cout << ++last_even;
	return EXIT_SUCCESS;
}