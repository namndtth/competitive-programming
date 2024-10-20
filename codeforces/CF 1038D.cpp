#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 5e5 + 5;
ll n, minval = 1e9, ans = 0;
ll a[N];
bool checkpos = 0, checkneg = 0;

int main()
{
    cin >> n;
    if (n == 1)
    {
        int k;
        cin >> k;
        cout << k;
        exit(0);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        minval = min(abs(a[i]), minval);
        checkpos |= (a[i] >= 0);
        checkneg |= (a[i] <= 0);
        ans += abs(a[i]);
    }
    if (checkpos && checkneg)
        cout << ans;
    else
        cout << ans - 2 * minval;
    return 0;
}

