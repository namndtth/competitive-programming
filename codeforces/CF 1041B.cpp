#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull gcd(ull x, ull y)
{
    return (y == 0 ? x : gcd(y, x % y));
}
int main()
{
    ull a, b, x, y, w, h, ans = 0;

    cin >> a >> b >> x >> y;

    ull t = gcd(x, y);

    x /= t, y /= t;
    ans = min(a / x, b / y);

    cout << ans;
    return 0;
}
