#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    int sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        sum += s[i] - '0';
        bool ok = true;
        int pos = i + 1;
        int sum2 = 0;
        while (pos < n)
        {
            sum2 = s[pos++] - '0';
            while (pos < n && sum2 + s[pos] - '0' <= sum)
            {
                sum2 += s[pos] - '0';
                ++pos;
            }
            if (sum2 != sum) ok = false;
        }
        if (sum2 != sum) ok = false;
        if (ok)
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
