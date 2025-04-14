#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& val : a) cin >> val;

    vector b = a;
    if (k == 1) {
        sort(b.begin(), b.end());
        cout << (a == b ? "YES" : "NO") << endl;
    } else {
        cout << "YES" << endl;
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
