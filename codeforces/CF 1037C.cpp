#include <iostream>
#include <string>
using namespace std;

const int maxn = 1e6;
string a;
string b;
int n;

int main()
{
	int i, cost = 0;
	ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n;
	cin >> a >> b;
	for (i = 0; i < n; i++)
	{
		if (a[i] != b[i] && a[i + 1] != b[i + 1] && a[i] != a[i + 1])
		{
			cost++;
			i++;
		}
		else
			if (a[i] != b[i])
				cost++;
	}
	cout << cost;
	return 0;
}