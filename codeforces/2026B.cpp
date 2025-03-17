#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (ll &x : a) cin >> x;

    if (n == 1) {
        cout << 1 << endl;
        return;
    }

    // The distance between two consecutive cells is shortest
    // If n is even, calculate distances between a[i] and a[i + 1] (`i` even), take maximum of these distances => answer
    // else, remove a[i] at odd `i`, calculate as above for the rest
    ll ans = LLONG_MAX;
    if (n & 1) {
        for (int i = 0; i < n; i += 2) {
            ll temp = LLONG_MIN;
            for (int j = 0; j < n; j += 2) {
                if (i == j) ++j;
                temp = max(temp, j + 1 < n ? a[j + 1] - a[j] : 0);
            }

            ans = min(ans, temp);
        }
    } else {
        ans = LLONG_MIN;
        for (int i = 0; i < n; i += 2) {
            ans = max(ans, a[i + 1] - a[i]);
        }
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