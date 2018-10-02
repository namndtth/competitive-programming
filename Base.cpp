#include <bits/stdc++.h>
#include <string>
using namespace std;

string base("0123456789ABCDEF");
vector<int> converted;
int main()
{
    int x, y;
    cin >> x >> y;
    string z;
    cin >> z;
    int res = x * y;
    int i, j, pos = -1;
    for (i = 2; i <= 16; i++)
    {
        int t = res;
        converted.clear();
        while (t > 0)
        {
            converted.push_back(t % i);
            t /= i;
        }
        int sz = converted.size();
        if (z.size() == sz)
        {
            for (j = sz - 1;j >= 0;j--)
            {
                pos = i;
                cout << int(z[sz - j - 1] - '0') << endl;
                if (converted[j] != int(z[sz - j - 1] - '0'))
                {
                    pos = -1;
                    break;
                }
            }
            if (pos != -1)
            {
                cout << pos;
                return 0;
            }
        }
    }
    cout << pos;
    return 0;
}


