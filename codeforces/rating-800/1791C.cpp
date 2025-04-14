#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    string st;
    cin >> st;

    int i{0}, j{n - 1};
    while (i < j && ((st[i] == '0' && st[j] == '1') || (st[i] == '1' && st[j] == '0'))) ++i, --j;

    cout << j - i + 1 << endl;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }

    return EXIT_SUCCESS;
}
