#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int num_odds = 0;
        for (int i = 0; i < n; i++)
        {
            int a; cin >> a;
            if (a % 2 != 0)
                num_odds++;
        }
        if (num_odds == 0)
            cout <<  "No" << endl;
        else if (num_odds % 2 == 0 && x == n)
            cout <<  "No" << endl;
        else if (num_odds == n && x % 2 == 0)
            cout <<  "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}