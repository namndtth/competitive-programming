#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int& val : a) cin >> val;

    cout << (a[0] == 1 ? "YES" : "NO") << endl;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
    return EXIT_SUCCESS;
}
