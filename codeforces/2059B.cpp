/**
 * @note if problem includes multiple segments then we might concentrate on one segment
 * With this problem, we should focus on 2nd subarray
 * The answer does not exceed 2
 * Iterate over possible starting position of 2nd array
 * If there is a position does not equal 1 => answer is 1
 * if they're all 1s => answer is 2: [1, 1, 1, 2, 2] => [1], [1, 1], [2], [2] => [1, 1, 2, 0]
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (auto &val : a) cin >> val;

    if (n == k) {
        for (int i = 2; i <= n; i += 2) {
            if (a[i - 1] != i / 2) {
                cout << i / 2 << endl;
                return;
            }
        }
        cout << k / 2 + 1 << endl;
    } else {
        for (int i = 2; i <= n - k + 2; ++i) {
            if (a[i - 1] != 1) {
                cout << 1 << endl;
                return;
            }
        }
        cout << 2 << endl;
    }
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }

    return EXIT_SUCCESS;
}