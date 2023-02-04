#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = ll(1e6);

int main()
{
    ll n, x, ans = INT_MIN;
    cin >> n;

    ll *sum = new ll[N];
    sum[0] = 0;
    ll *sumNeg = new ll[N];
    sumNeg[0] = 0;
    bool ok = false;
    for (ll i = 1;i <= n;i++)
    {
        cin >> x;
        if (x > 0)
            ok = true;
        if (!ok)
            sumNeg[i] += sumNeg[i - 1] + x;

        sum[i] = sum[i - 1] + x;
        if (sum[i] < 0)
            sum[i] = 0;
        if (ans < sum[i])
            ans = sum[i];
    }
    if (!ok)
        cout << sumNeg[n];
    else
        cout << ans;
    return 0;
}
