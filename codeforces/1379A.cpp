//
// Created by nampc on 11/20/2023.
//
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORN(i, a, b) for (int i = a; i <= b; i++)
#define FORR(i, b, a) for (int i = b - 1; i >= a; i--)
#define FORRN(i, b, a) for (int i = b; i >= a; i--)

using vi = vector<int>;
using vvi = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vii = vector<pair<int, int>>;

void print(string& st)
{
	const int n = st.size();
	cout << "YES" << endl;
	FOR(i, 0, n) if (st[i] == '?') st[i] = 'd';
	cout << st << endl;
}
int count(const string& st, const string& sample)
{
	const int n = st.size();
	int cnt = 0;
	FOR(i, 0, n)
	{
		if (st.substr(i, sample.size()) == sample)
			cnt++;
	}
	return cnt;
}

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		string st;
		cin >> st;
		const string sample = "abacaba";
		bool F = false;

		for (int i = 0; i + sample.size() <= n; i++)
		{
			string ss = st;
			bool found = true;
			FOR(j, 0, sample.size())
			{
				if (st[i + j] != '?' && st[i + j] != sample[j])
				{
					found = false;
					break;
				}
				ss[i + j] = sample[j];
			}
			if (found && count(ss, sample) == 1)
			{
				for (int j = 0; j < n; j++)
				{
					if (ss[j] == '?')
					{
						ss[j] = 'd';
					}
				}
				F = true;
				cout << "Yes\n";
				cout << ss << "\n";
				break;
			}
		}
		if (!F) cout << "NO" << endl;
	}
	return EXIT_SUCCESS;
}
