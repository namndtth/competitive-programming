#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    map<int, int> cnt;
    for (int i = 0; i < n; ++i) { int val; cin >> val; cnt[val]++; }

    int ans{cnt[-1] % 2 ? 1: 0}; cnt[-1] -= ans; cnt[1] += ans;
    while (cnt[-1] > cnt[1]) { ans += 2; cnt[-1] -= 2; cnt[1] += 2; }
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
