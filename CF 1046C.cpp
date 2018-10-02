#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 5;
int main()
{
    int n, d;
    scanf("%d%d", &n, &d);
    int r[N], p[N];
    int i, j;
    for (i = 1 ; i <= n; i++)
        scanf("%d", &r[i]);
    for (i = 1 ; i <= n; i++)
        scanf("%d", &p[i]);
    int np = r[d] + p[1];
    int nr = d;
    for (i = d - 1, j = n; i >= 1; i--, j--)
    {
        if (r[i] + p[j] <= np)
            nr--;
        else
            break;
    }
    cout << nr;
    return 0;
}
