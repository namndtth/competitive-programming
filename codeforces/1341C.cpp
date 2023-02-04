#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> p(n), pos(n);
    vector<bool> filled(n, false);

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        pos[--p[i]] = i;
    }

    for (int i = 0; i < n; i++)
    {
        if (filled[i])
            continue;

        int current = pos[i];

        while (current < n)
        {
            filled[current] = true;
            if (current + 1 == n)
                break;

            if (filled[current + 1])
                break;

            if (p[current + 1] == p[current] + 1)
            {
                current++;
                continue;
            }
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}
int main()
{
    freopen("data.inp", "r", stdin);
    int tc;
    cin >> tc;
    while (tc--)
        solve();
    return 0;
}
