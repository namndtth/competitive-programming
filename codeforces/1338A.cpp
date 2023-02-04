#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc; cin >> tc;
    while (tc--)
    {
        int n; cin >> n;
        vector<int> a(n);
        int difference = 0;
        int ans = -1;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 1; i < n; i++)
        {
            if (a[i] < a[i - 1])
            {
                difference = max(difference, a[i - 1] - a[i]);
                a[i] = a[i - 1];
            }
        }
        if (difference == 0)
            cout << "0\n";
        else
            cout << floor(log2(difference)) + 1 << endl;
    }
    return 0;
}
