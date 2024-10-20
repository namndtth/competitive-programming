#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;
int n;
int a[maxn];

int main()
{
    cin >> n;
    int i;
    for (i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int min = a[0], max = a[n - 1];
    cout << a[n - 1] - a[0] - n + 1;
    return 0;
}
