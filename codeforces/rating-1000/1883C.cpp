#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    int result{INT_MAX}, even{0};
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        if (!(val & 1)) ++even;
        result = min(result, val % k == 0 ? 0 : k - val % k);
    }

    if (k == 4) {
        if (even >= 2 || result == 0) cout << "0\n";
        else {
            cout << min(result, 2 - even) << endl;
        }
    } else {
        cout << result << endl;
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
