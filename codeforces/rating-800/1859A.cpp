#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& val : a) cin >> val;

    auto mn = min_element(a.begin(), a.end());
    vector<int> b, c;
    for (int i = 0; i < n; ++i) {
        if (a[i] == *mn)
            b.push_back(a[i]);
        else
            c.push_back(a[i]);
    }

    if (b.empty() || c.empty()) cout << -1 << endl;
    else {
        cout << b.size() << ' ' << c.size() << endl;
        for (auto val: b) cout << val << ' '; cout << endl;
        for (auto val: c) cout << val << ' '; cout << endl;
    }
}

int main() {
    int tc;
    cin >>tc;

    while (tc--) {
        solve();
    }

    return EXIT_SUCCESS;
}
