#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n, k;
    cin >> n >> k;
    ll a = n - k, b = n - 2 * k;
    if (n % 2 == 0 || n % k == 0 || (a > 0 && a % 2 == 0) || (b > 0 && b % 2 == 0))
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }

    return EXIT_SUCCESS;
}
