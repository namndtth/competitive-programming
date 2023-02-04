//
// Created by NAMND on 12/25/2020.
//

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		vector<vector<string>> call_forwarding;

		while (true)
		{
			vector<string> request(4);
			cin >> request[0];
			if (request[0] == "0000")
				break;
			for (auto i = 1; i < 4; i++)
				cin >> request[i];
			call_forwarding.push_back(request);
		}

		while (true)
		{
			vector<string> request(2);
			cin >> request[0];
			if (request[0] == "9000")
				break;

		}
	}
}