#include <bits/stdc++.h>
using namespace std;

const int N = 200000;
int a[N];

int main()
{
    int n, i, x, f;
    scanf("%d", &n);
    for (i = 0;i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d %d", &x, &f);
    long long ans = 0;
    for (i = 0;i < n; i++)
    {
        if (a[i] > x)
        {
            a[i] -= x;
            ans += ceil(float(a[i]) / (x + f));
        }
    }
    ans *= f;
    cout << ans;
    return 0;
}
