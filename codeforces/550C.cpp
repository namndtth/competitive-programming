//
// Created by nampc on 9/19/2023.
//
#include <bits/stdc++.h>
using namespace std;

int main()
{
	string st;
	cin >> st;
	vector<string> divisor;
	for (int i = 0; i < 1000; i++)
		if (i % 8 == 0)
			divisor.push_back(to_string(i));

	for (const auto& div : divisor)
	{
		bool found = true;
		int pos = -1;
		for (auto n : div)
		{
			pos = st.find(n, pos + 1);
			if (pos == string::npos)
			{
				found = false;
				break;
			}
		}
		if (found)
		{
			cout << "YES\n" << div << endl;
			return EXIT_SUCCESS;
		}
	}
	cout << "NO\n";
	return EXIT_SUCCESS;
}
