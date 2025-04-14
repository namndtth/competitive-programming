#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    map<int, int> pos;
    for (int i = 0, p = 1; i < n; ++i) {
        int val; cin >> val;
        if (val == 2) pos[p++] = i;
    }

    if (pos.size() & 1) cout << "-1\n";
    else cout << pos[pos.size() / 2] + 1 << endl;
}

int main() {
    int tc; cin >> tc;

    while (tc--) solve();

    return EXIT_SUCCESS;
}
