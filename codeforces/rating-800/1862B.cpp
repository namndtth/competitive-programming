#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int& val : a) cin >> val;

    vector b{a.front()};
    for (int i = 1; i < n; ++i) {
        if (a[i - 1] != 1 && a[i] < a[i - 1]) {
            b.push_back(1);
        }
        b.push_back(a[i]);
    }
    cout << b.size() << endl;
    for (int val : b) cout << val << ' ';
    cout << endl;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }

    return EXIT_SUCCESS;
}
