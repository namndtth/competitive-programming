#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> result;
    for (int i = 0; i < n; ++i) {
        int val; cin >> val;
        result.push_back(n + 1- val);
    }
    for (int val: result) cout << val << ' ';
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

