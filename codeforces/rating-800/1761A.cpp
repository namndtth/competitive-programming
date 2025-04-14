
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    if ((n == a && a == b) || (a + b + 1 < n)) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }

    return EXIT_SUCCESS;
}
