#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    bool isIndefinite{true};
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] <= i * 2 || a[i] <= (n - 1 - i) * 2) {
            isIndefinite = false;
        }
    }
    cout << (isIndefinite ? "YES" : "NO") << endl;
}
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return EXIT_SUCCESS;
}
