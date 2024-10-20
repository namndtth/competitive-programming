#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, a[101];
    cin >> n;
    cin >> m;
    int i;
    int maxx = -1;
    int sum = m;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        if (maxx < a[i])
            maxx = a[i];
    }
    cout << max((int)ceil((double)sum / n), maxx) << " " << maxx + m;
    return 0;
}
