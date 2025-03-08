/// Note: we can choose j repeatedly
/// Insert -INF into `a` before a.begin()
/// Sort `b` in asc order
/// a[i] = b[j] - a[i] and a[i - 1] <= a[i] => a[i - 1] <= b[j] - a[i] => a[i - 1] + a[i] <= b[j]
/// => binary search in b the smallest element that satisfies greater or equal a[i - 1] + a[i]
// There are four cases. Each case is handled and explained as below.

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int &val : a) cin >> val;
    a.insert(a.begin(), numeric_limits<int>::min());
    for (int &val : b) cin >> val;

    sort(b.begin(), b.end());

    for (int i = 1; i <= n; ++i) {
        auto lower = lower_bound(b.begin(), b.end(), a[i - 1] + a[i]);
        if (lower == b.end()) {
            // lower == b.end() && a[i - 1] > a[i] => no output
            if (a[i - 1] > a[i]) {
                cout << "NO" << endl;
                return;
            }
            // lower == b.end() && a[i - 1] <= a[i] => a[i] unchanged
        } else {
            // lower != b.end && a[i - 1] > a[i] => we only can choose *lower - a[i]
            // lower != b.end && a[i - 1] <= a[i] => take min value
            a[i] = a[i - 1] > a[i] ? *lower - a[i] : min(a[i], *lower - a[i]);
        }
    }

    cout << "YES" << endl;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }

    return EXIT_SUCCESS;
}