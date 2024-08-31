//
// Created by nampc on 9/10/2023.
//

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k1, k2;
	cin >> n;
	list<int> cards1, cards2;
	cin >> k1;
	int x;
	for (int i = 0; i < k1; i++)
	{
		cin >> x;
		cards1.push_back(x);
	}
	cin >> k2;
	for (int i = 0; i < k2; i++)
	{
		cin >> x;
		cards2.push_back(x);
	}

	int c1, c2;
	int turns = 0;
	while (!cards1.empty() && !cards2.empty())
	{
		c1 = cards1.front();
		cards1.pop_front();
		c2 = cards2.front();
		cards2.pop_front();
		if (c1 > c2)
		{
			cards1.push_back(c2);
			cards1.push_back(c1);
		}
		else {
			cards2.push_back(c1);
			cards2.push_back(c2);
		}
		turns++;
		if (cards1.empty())
			cout << turns << " 2" << endl;
		if (cards2.empty())
			cout << turns << " 1" << endl;
		if (turns >= pow(2, n))
		{
			cout << "-1" << endl;
			return EXIT_SUCCESS;
		}
	}
	return EXIT_SUCCESS;
}
