//
// Created by nampc on 10/15/2023.
//
#include <bits/stdc++.h>
using namespace std;

double factor(int n)
{
	double res = 1.0;
	for (int i = 2; i <= n; i++)
		res *= i;
	return res;
}
double combination(int k, int n)
{
	return factor(n) / factor(k) / factor(n - k);
}

int main()
{
	string st1, st2;
	cin >> st1 >> st2;

	int end_s1 = 0, end_s2 = 0;
	int moves = 0;
	int n = (int)st1.size();
	for (int i = 0; i < n; i++)
	{
		end_s1 += (st1[i] == '+' ? 1 : -1);
		if (st2[i] == '?')
			moves++;
		else
			end_s2 += (st2[i] == '+' ? 1 : -1);
	}

	cout << fixed << setprecision(12);
	int distance = abs(end_s2 - end_s1);
	if (moves == 0)
	{
		cout << (end_s1 == end_s2 ? 1.0 : 0.0) << endl;
	}
	else if (moves < distance || ((moves - distance) % 2 != 0))
	{
		cout << 0.0 << endl;
	}
	else
	{
		cout << combination(distance + (moves - distance) / 2, moves) / (1 << moves) << endl;
	}

	return EXIT_SUCCESS;
}
