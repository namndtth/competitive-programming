#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    cout << (n % 3 == 0 ? "Second" : "First") << endl;
}
int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }

    return EXIT_SUCCESS;
}