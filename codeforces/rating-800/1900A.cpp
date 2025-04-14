#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    string st;
    cin >> st;

    int result{0};
    for (int i = 0; i < n; ++i) {
        if (st[i] == '.') {
            int j = i;
            while (j < n && st[j] == '.') ++j;

            if (j - i > 2) {
                cout << 2 << endl;
                return;
            }

            result += j - i;
            i = j;
        }
    }

    cout << result << endl;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }

    return EXIT_SUCCESS;
}
