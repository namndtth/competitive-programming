//
// Created by nampc on 10/22/2023.
//
#include <bits/stdc++.h>
using namespace std;

bool find(int n, int a, int b)
{
	if (n <= 0)
		return false;
	if (n == 1)
		return true;
	if (n % a == 0)
		return (n / a, a, b) || find(n - b, a, b);
	else
		return find(n - b, a, b);
}

int main()
{
	int n, a, b;
	cin >> n >> a >> b;
	if (find(n, a, b))
		cout << "YES\n";
	else
		cout << "NO\b";
	return EXIT_SUCCESS;
}
