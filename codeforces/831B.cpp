#include <bits/stdc++.h>
using namespace std;

int main()
{
	string firstLayout, secondLayout;
	cin >> firstLayout >> secondLayout;

	map<char, char> m;
	for (int i = 0; i < 26; i++)
	{
		m[firstLayout[i]] = secondLayout[i];
		m[firstLayout[i] - 32] = secondLayout[i] - 32;
	}

	string text;
	cin >> text;
	for (auto & c: text)
	{
		cout << (m[c] ? m[c] : c);
	}

	return EXIT_SUCCESS;
}
