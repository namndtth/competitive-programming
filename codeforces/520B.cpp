#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    if (n >= m) {
        cout << n - m << endl;
    } else {
        int ans{0};
        while (n * 2 < m) {
            n *= 2;
            ++ans;
        }
        if (m - n <= 1 + n * 2 - m)
            ans += m - n;
        else
            ans += 1 + n * 2 - m;
        cout << ans << endl;
    }
}

int main() {
    solve();
    return EXIT_SUCCESS;
}
