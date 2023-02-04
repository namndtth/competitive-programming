#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn = 100000;
										
int n;
priority_queue<int> a, b;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	int x, i;
	for (i = 0; i < n; i++)
	{
		cin >> x;
		a.push(x);
	}
	for (i = 0; i < n; i++)
	{
		cin >> x;
		b.push(x);
	}
	ll as = 0, bs = 0;
	int ea, eb;
	while (!a.empty() || !b.empty())
	{
		//a's movement
		if (a.empty() && !b.empty())
			b.pop();
		else
			if (!a.empty() && b.empty())
			{
				as += a.top();
				a.pop();
			}
			else
				if (!a.empty() && !b.empty())
				{
					ea = a.top();
					eb = b.top();

					if (ea >= eb)
					{
						as += ea;
						a.pop();
					}
					else
						b.pop();
				}
		//b's movement
		if (a.empty() && !b.empty())
		{
			bs += b.top();
			b.pop();
		}
		else
			if (b.empty() && !a.empty())
			{
				a.pop();
			}
			else
				if (!b.empty() && !a.empty())
				{
					ea = a.top();
					eb = b.top();
					if (eb >= ea)
					{
						bs += eb;
						b.pop();
					}
					else
						a.pop();
				}
				else
				{
					as += a.top();
					a.pop();
				}
	}

	cout << as - bs;
	return 0;
}
