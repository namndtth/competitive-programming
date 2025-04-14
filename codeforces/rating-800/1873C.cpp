#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<string> target(10);
    for (int i = 0; i < 10; ++i) cin >> target[i];

    int result{0};
    for (int row = 0; row < 10; ++row) {
        for (int col = 0; col < 10; ++col) {
            if (target[row][col] == 'X') {
                result += min(min(row + 1, col + 1), min(10 - row, 10 - col));
            }
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
