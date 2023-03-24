#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y)
{
    if (y == 0) return x;
    return gcd(y, x % y);
}

int lcm(int x, int y)
{
    return (x * y) / gcd(x, y);
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    if (n < 3)
    {
        cout <<"YES\n";
        return;
    }
    
    for (int i = 1; i < n - 1; i++)
    {
        int x = lcm(a[i - 1], a[i]);
        int y = lcm(a[i], a[i + 1]);
        if (gcd(x, y) != a[i])
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main()
{
    int t; 
    cin >> t;
    while (t--)
    {
        solve();
    }
}
