#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    int sum{0};
    for (int i = 0; i < n; ++i) { int val; cin >> val; sum += val; }

    cout << (sum % 2 == 0 ? "YES" : "NO") << endl;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }

    return EXIT_SUCCESS;
}

