#include <iostream>
#include <limits>
using namespace std;
typedef pair<int, int> ii;
#define fi first
#define sc second
struct rectangle
{
	ii topLeft;
	ii btmRight;
	rectangle()
	{
		topLeft.fi = 0;
		topLeft.sc = 0;
		btmRight.fi = 0;
		btmRight.sc = 0;
	}
	rectangle(ii tl, ii br)
	{
		topLeft = tl;
		btmRight = br;
	}
};
int min(int x, int y)
{
	return (x < y ? x : y);
}
int max(int x, int y)
{
	return (x > y ? x : y);
}
rectangle *intersect(rectangle *a, rectangle *b)
{
	if (!a || !b)
		return nullptr;
	rectangle *c;
	c->topLeft.fi = max(a->topLeft.fi, b->topLeft.fi);
	c->topLeft.sc = max(a->topLeft.sc, b->topLeft.sc);
	c->btmRight.fi = min(a->btmRight.fi, b->btmRight.fi);
	c->btmRight.sc = min(a->btmRight.sc, b->btmRight.sc);
	if (c->topLeft.fi > c->topLeft.sc || c->topLeft.sc > c->btmRight.sc)
		return nullptr;
	return c;
}
void solve()
{
	int n;
	cin >> n;
	rectangle *recs = new rectangle[n];
	for (int i = 0; i < n; i++)
	{
		ii tl, br;
		cin >> tl.fi >> tl.sc >> br.fi >> br.sc;
		recs[i] = rectangle(tl, br);
	}
	rectangle *pre = new rectangle[n + 1];
	rectangle *suf = new rectangle[n + 1];
	pre[0] = suf[0] = rectangle(ii(INT_MIN, INT_MIN), ii(INT_MAX, INT_MAX));
	for (int i = 1; i <= n; i++)
	{
		pre[i] = *intersect(&recs[i - 1], &pre[i - 1]);
		suf[i] = *intersect(&recs[n - i], &suf[i - 1]);
	}
	for (int i = 0; i <= n; i++)
	{
		if (!&pre[i])
		{
			rectangle intersection = intersection
		}
	}
}
int main()
{
	pair<int, int> topLeft, btmRight;

}