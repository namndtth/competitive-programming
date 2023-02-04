#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string s;
        cin >> s;
        int n = int(s.length());
        long long res = 0, cnt = 0;

        for (int i = 1; i <= n; i++)
        {
            if (s[i - 1] == '-')
                cnt--;
            else cnt++;
            if (cnt < 0 && i < n)
            {
                cnt = 0;
                res += i;
            }
        }
        if (cnt < 0)
            res += 2 * n;
        else res += n;
        cout << res << endl;
    }

    return 0;
}
