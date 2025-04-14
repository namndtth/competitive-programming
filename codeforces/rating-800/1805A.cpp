#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& e : a) cin >> e;

    int res;
    for (int x = 0; x < 256; x++) {
        res = a[0] xor x;
        for (int i = 1; i < n; i++) res = res xor (a[i] xor x);
        if (res == 0) {
            cout << x << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return EXIT_SUCCESS;
}