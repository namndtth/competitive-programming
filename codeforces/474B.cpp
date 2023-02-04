#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, x;

    cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a[i + 1] = a[i] + x;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        int ans = lower_bound(a.begin(), a.end(), x) - a.begin();
        cout << ans << endl;
    }
    return 0;
}