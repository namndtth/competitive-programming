#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll sum(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    return (n - 1) + sum(n - 1);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int x;
        map<int, int> freq;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            freq[x - i]++;
        }
        ll ans = 0;
        for (auto it : freq)  
            ans += sum(it.second);
        
        cout << ans << endl;
    }
    return 0;
}