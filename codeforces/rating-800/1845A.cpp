#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;

    if (x != 1) {
        cout << "YES\n" << n << endl;
        for (int i = n; i > 0; --i) cout << "1 ";
    } else if (k == 1 || (k == 2 && n % 2 == 1)) {
        cout << "NO";
    } else {
        cout << "YES\n" << n / 2 << endl;
        cout << (n % 2 == 0 ? 2 : 3) << ' ';
        for (int i = 0; i < n / 2 - 1; ++i) cout << "2 ";
    }
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
