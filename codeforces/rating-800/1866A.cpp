#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int result{INT_MAX};
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        result = min(result, abs(val));
    }

    cout << result << endl;
}

int main() {
    solve();

    return EXIT_SUCCESS;
}
