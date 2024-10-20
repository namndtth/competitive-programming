#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    // freopen("data.inp", "r", stdin);

    int n, t; cin >> n >> t;

    vector<int> a(n);
    vector<ll> tot(n + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        tot[i + 1] = tot[i] + a[i];
    }

    int num_books = 0;
    for (int i = n; i > 0; i--)
    {
        auto low = lower_bound(tot.begin(), tot.end(), tot[i] - t);
        if (i - (low - tot.begin()) > num_books)
            num_books = i - (low - tot.begin());
    }
    cout << num_books << endl;
    return 0;
}
