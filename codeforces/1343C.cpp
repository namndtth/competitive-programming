#include <bits/stdc++.h>
#define ll long long
#define MAXN (int)2e5
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> max_sub;
        for (int i = 0; i < n; i++)
            cin >> a[i];
            
        max_sub.push_back(a[0]);
        for (int i = 1; i < n; i++)
        {
            int x = max_sub.back();
            if ((ll)x * a[i] > 0)
            {
                if (x < a[i])
                {
                    max_sub.pop_back();
                    max_sub.push_back(a[i]);
                }
            }
            else
                max_sub.push_back(a[i]);
        }

        ll ans = 0;
        for (int i = 0; i < max_sub.size(); i++)
            ans += max_sub[i];
        
        cout << ans << endl;
    }
    return 0;
}