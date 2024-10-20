//
// Created by nampc on 9/14/2023.
//
#include <bits/stdc++.h>
using namespace std;

bool compare(const string& st, const string& s1, const string& s2)
{
	int n = (int)st.size();
	int i = 0;
	string fi, se;
	while (i < n - 1)
	{
		fi = st.substr(i, 2);
		if (fi == s1)
		{
			int j = i + 2;
			while (j < n - 1)
			{
				se = st.substr(j, 2);
				if (se == s2)
					return true;
				j++;
			}
			return false;
		}
		i++;
	}
	return false;
}


int main()
{
	string st;
	cin >> st;

	if (compare(st, "AB", "BA") || compare(st, "BA", "AB"))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return EXIT_SUCCESS;
}
