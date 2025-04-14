#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& val : a) cin >> val;

    sort(a.begin(), a.end(), std::greater<int>());

    if (all_of(a.begin(), a.end(), [&](int val) { return val == a[0]; })) {
        cout << "NO\n";
        return;
    }

    for (int i = 1; i < n; ++i) {
        if (a[0] != a[i]) {
            swap(a[0], a[i]);
            break;
        }
    }

    cout << "YES\n";
    for (int val : a) cout << val << " ";
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