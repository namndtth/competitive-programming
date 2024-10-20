#include <bits/stdc++.h>

using namespace std;

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;

		vector<int> a(n), b(n);

		for (auto& x : a) cin >> x;
		for (auto& x : b) cin >> x;
		auto bReversed = b;
		reverse(bReversed.begin(), bReversed.end());

		cout << ((a == b || a == bReversed) ? "Bob" : "Alice") << endl;
	}
	return EXIT_SUCCESS;
}
