#include <bits/stdc++.h>

using namespace std;

vector<int> count_chars(const string& s)
{
	vector<int> result(26);
	for (auto& ch : s)
		result[ch - 'a']++;

	return result;
}

string make_output(vector<int> & cnt)
{
	string result;

	int x = 25, y = 24;
	while ()
	}
}

void solve()
{
	int n;
	cin >> n;

	string s;
	cin >> s;

	map<char, int> cnt = count_chars(s);

	string ans = make_output(cnt);

	cout << ans << endl;
}

int main()
{
	solve();
	return EXIT_SUCCESS;
}
