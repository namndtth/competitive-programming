#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto& x: a) cin >> x;

    sort(a.begin(), a.end());

    int ans{accumulate(a.begin(), a.end() - 2 * k, 0)};
    for (int i = n - 2 * k; i < n - k; i++)
    {
        int j = i + k;
        ans += a[i] / a[j];
    }

    cout << ans << endl;
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
