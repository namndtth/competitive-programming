#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int result{0};
    for (int i = 0; i < n - 1; ++i) {
        int val;
        cin >> val;
        result += val;
    }
    cout << -result << endl;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
    return EXIT_SUCCESS;
}
