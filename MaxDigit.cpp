#include <bits/stdc++.h>
using namespace std;
int main()
{
    string number;
    cin >> number;
    int sz = number.length();
    int ans = -1;
    for (int i = 0; i < sz; i++)
    {
        if (ans < (int)(number[i] - '0'))
            ans = (int)(number[i] - '0');
    }
    cout << ans;
    return 0;
}
