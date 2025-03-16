#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;

    // For each value of k^n
    // Find a range [l, r] in which l2 <= l * k ^ n && k ^ n <= r2
    // Add r - l + 1 to the final answer
    ll ans = 0, n = 0;
    while (pow(k, n) <= 1e9) {
        ll p = pow(k, n);
        ll a = max<ll>(ceil(l2 * 1.0 / p), l1), b = min<ll>(floor(r2 * 1.0 / p), r1);

        if (b >= a) ans += b - a + 1;

        ++n;
    }

    cout << ans << endl;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }

    return EXIT_SUCCESS;
}