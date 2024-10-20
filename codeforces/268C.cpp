//
// Created by nampc on 10/14/2023.
//
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	cout << min(n, m) + 1 << endl;
	for (int i = 0; i < min(n, m) + 1; i++)
		cout << i << " " << min(n, m) - i << endl;
	return EXIT_SUCCESS;
}
