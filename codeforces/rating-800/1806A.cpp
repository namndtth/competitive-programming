#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll ans{-1};
    if (d >= b && c <= a + d - b) {
        ans = a + 2 * (d - b) - c;
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
