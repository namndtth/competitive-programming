#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &val : a) cin >> val;

    int result{INT_MAX};
    for (int i = 1; i < n; ++i) {
        result = min(result, a[i] - a[i - 1]);
    }
    cout << (result < 0 ? 0 : static_cast<int>(ceil((result + 1) / 2.0))) << endl;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }

    return EXIT_SUCCESS;
}
