#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    ll n, k;
    cin >> n >> k;

    vector<int> p(n);
    iota(p.begin(), p.end(), 1);

    ll i{0}, j{n - 1};
    while (i < j)
    {
        if (k >= 2 * (j + 1 - p[i]))
        {
            k -= 2 * (j + 1 - p[i]);
            swap(p[i], p[j]);
            ++i;
            --j;

            if (k == 0) break;
        }
        else
            --j;
    }

    if (k == 0)
    {
        cout << "Yes" << endl;
        for (const auto& x: p) cout << x << ' ';
        cout << endl;
    }
    else
        cout << "No" << endl;
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
