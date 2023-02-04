#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("data.inp", "r", stdin);

    int n; cin >> n;

    int num_4s = INT_MAX;
    int num_total = INT_MAX;

    for (int i = n / 4; i >= 0; i--)
    {
        int j = n - i * 4;
        if (j % 7 == 0 && i + j / 7 < num_total)
        {
            num_total = i + j / 7;
            num_4s = i;
        }
    }

    if (num_total != INT_MAX)
    {
        for (int i = 0; i < num_4s; i++)
            cout << '4';
        for (int i = 0; i < num_total - num_4s; i++)
            cout << '7';
        cout << endl;
    }
    else
        cout << "-1\n";
    return 0;
}
