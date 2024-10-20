#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	string encoded;
	cin >> encoded;

	vector<char> decoded(n);

	int cur = (n - 1) / 2, sign = (n & 1 ? 1 : -1);
	for (int i = 0; i < n; i++)
	{
		cur += sign * i;
		decoded[cur] = encoded[i];
		sign *= -1;
	}

	for (auto &ch: decoded)
		cout << ch;

	return EXIT_SUCCESS;
}
