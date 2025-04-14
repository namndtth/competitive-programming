#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        cnt[val]++;
    }

    if (cnt.size() == 1)
        cout << "Yes" << endl;
    else if (cnt.size() > 2)
        cout << "No" << endl;
    else {
        auto fi = cnt.begin(), se = std::next(cnt.begin());
        cout << (abs(fi->second - se->second) <= 1 ? "Yes" : "No") << endl;
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
