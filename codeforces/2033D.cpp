#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    // insert 0 for case we meet 0 or sum some number at the beginning equals 0
    set visited{0ll};

    ll ans{0}, sum{0};
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;

        sum += x;
        // a + b + c and b + c = 0 => a + b + c = a
        // using a set to check whether we meet `a` again
        if (visited.find(sum) == visited.end()) {
            visited.insert(sum);
        } else {
            ans += 1;
            sum = 0ll;
            visited = {0ll};
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