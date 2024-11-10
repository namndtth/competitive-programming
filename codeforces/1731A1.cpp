#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<pair<int, int>> ans;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    if (accumulate(a.begin(), a.end(), 0) & 1)
    {
        cout << -1 << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (i & 1)
        {
            if (a[i - 1] == a[i]) ans.emplace_back(i, i + 1);
            else
            {
                ans.emplace_back(i, i);
                ans.emplace_back(i + 1, i + 1);
            }
        }
    }

    cout << ans.size() << endl;
    for (auto& [fi, se]: ans) cout << fi << ' ' << se << endl;
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
