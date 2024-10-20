#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        total += a[i];
    }
    
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int sum = total;
        for (int j = i; j < n; j++)
        {
            sum += (a[j] == 0) ? 1 : -1;
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
    return 0;
}