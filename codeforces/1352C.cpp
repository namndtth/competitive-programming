#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    freopen("data.inp", "r", stdin);

    int t; cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (n > k)
            cout << k << endl;
        else if (n == k)
        {
            cout << n + 1 << endl;
        }
        else
        {
            int num_cycles = k / (n - 1);

            int rmd = k - (n - 1) * num_cycles;

            if (rmd == 0)
                rmd -= 1;

            cout << n * num_cycles + rmd << endl;
        }
    }
    return 0;
}
