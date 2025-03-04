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

int main()
{
	int n;
	cin>>n;
	if (n==1)
		cout << n ;
	else if (n>1)
	{
		cout << n <<" ";
		while (n != 1)
		{
			if (n % 2 == 0)
			{
				n = n / 2;
			}
			else
			{
				n = n * 3 + 1;
			}
			cout << n <<" ";
		}
	}

	return EXIT_SUCCESS;
}
