#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int &val : a) cin >> val;

    int ans{max(a[0], 2 * (x - a[n - 1]))};
    for (int i = 1; i < n; ++i) {
        ans = max(ans, a[i] - a[i - 1]);
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
