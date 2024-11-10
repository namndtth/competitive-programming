#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    ll str, intl, exp;
    cin >> str >> intl >> exp;

    if (ll mx{str + exp}, tot{str + intl + exp}; mx > intl)
        cout << mx - max(str, tot / 2 + 1) + 1 << endl;
    else
        cout << 0 << endl;
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
