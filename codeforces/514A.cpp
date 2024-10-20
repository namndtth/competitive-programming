#include <bits/stdc++.h>
using namespace std;

int main()
{
    string t; 
    cin >> t;
    if (t[0] - '0' != 9 && (9 - (t[0] - '0')) < (t[0] - '0'))
        t[0] = 9 - (t[0] - '0') + '0';
    for (int i = 1; i < t.length(); i++)
    {
        if ((9 - (t[i] - '0')) < (t[i] - '0'))
            t[i] = (9 - (t[i] - '0')) + '0';
    }
    cout << t << endl;
    return 0;
}