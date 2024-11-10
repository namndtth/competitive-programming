#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& x: a) cin >> x;

    long long ans{0}, i{0}, j{0};
    while (i < n && j < n)
    {
        while (j < n && a[j] >= j - i + 1)
        {
            ans += j - i + 1;
            j++;
        }
        i++;
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
