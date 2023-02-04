#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        int a = 1, b = n - a;
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                a = (n / i);
                b = n - (n / i);
                break;
            }
        }
        cout << a << " " << b << endl;
    }
    return 0;
}
