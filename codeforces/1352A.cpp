#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("data.inp", "r", stdin);
    int t; cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> ans;
        while (n > 0)
        {
            ans.push_back(n % 10);
            n /= 10;
        }
        int total = 0;
        for (int i = 0; i < (int)ans.size(); i++)
        {
            if (ans[i] != 0)
                total++;
        }
        cout << total << endl;
        for (int i = 0; i < (int)ans.size(); i++)
        {
            if (ans[i] != 0)
            cout << ans[i] * pow(10, i) << " ";
        }
        cout << endl;
    }
}
