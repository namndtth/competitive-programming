#include <bits/stdc++.h>
using namespace std;

void addDivs(int x, map<int, int> &divs)
{
    int i = 2;
    while (i * i <= x)
    {
        while (x % i == 0)
        {
            divs[i]++;
            x /= i;
        }
        i++;
    }

    if (x > 1) divs[x]++;
}

void solve()
{
    int n;
    cin >> n;

    map<int, int> divs;

    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        addDivs(x, divs);
    }

    for (const auto &[_, val]: divs)
    {
        if (val % n != 0)
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}


int main()
{
    int tc;
    cin >> tc;

    while (tc--)
    {
        solve();
    }

    return EXIT_SUCCESS;
}