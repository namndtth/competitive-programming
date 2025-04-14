#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, k;
    cin >> x >> k;
    if (x % k == 0) cout << "2\n" << x - 1 << " 1" << endl;
    else cout << "1\n" << x << endl;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }

    return EXIT_SUCCESS;
}
