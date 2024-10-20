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
        int a[n];
        int zero = 0, one = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 0)
                zero++;
            else
                one++;
        }

        if (one <= n / 2)
        {
            cout << zero << endl;
            for (int i = 0; i < zero; i++)
                cout << 0 << " ";
        }
        else if (zero < n / 2)
        {
            if (one % 2 != 0)
            {
                cout << one - 1 << endl;
                for (int i = 0; i < one - 1; i++)
                    cout << 1 << " ";
            }
            else
            {
                cout << one << endl;
                for (int i = 0; i < one; i++)
                    cout << 1 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
