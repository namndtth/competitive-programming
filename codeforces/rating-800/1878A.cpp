#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int& val : a) cin >> val;

    cout << (find(a.begin(), a.end(), k) == a.end() ? "NO" : "YES") << endl;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }

    return EXIT_SUCCESS;
}