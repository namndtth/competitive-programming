#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& val : a) cin >> val;

    int ans{0};
    for (int i = 0; i < n - 1; ++i) {
        // same pairity
        if (((a[i] + a[i + 1]) & 1) == 0) {
            int j = i + 1;
            while (j < n && ((a[j] + a[i]) & 1) == 0) ++j;
            ans += j - i - 1;
            i = j - 1;
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
