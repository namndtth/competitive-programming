#include <bits/stdc++.h>
using namespace std;

void print_bin(int val) {
    if (val == 0) {
        cout << 0 << endl;
        return;
    }

    vector<int> result;
    while (val) {
        result.insert(result.begin(), val & 1 ? 1 : 0);
        val /= 2;
    }

    for (auto& bit : result) cout << bit;
    cout << endl;
}

void solve() {
    int n;
    cin >> n;

    vector<int> results;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        // 32768 = 1000000000000000
        // 15    = 0000000000001111
        // => x2 15 times to remove all 1s
        // => Number of x2s not greater than 15 to remove all 1s
        // => number of additions are not able to greater than 15
        // 16 = 15 + 1 = 0000000000010000
        // => x2 11 times to remove all 1s

        int ans{INT_MAX};
        for (int j = 0; j <= 16; ++j) {
            int val{(x + j) % 32768};
            int tmp{j};
            while (val) {
                val = val * 2 % 32768;
                ++tmp;
            }

            ans = min(ans, tmp);
        }

        results.push_back(ans);
    }

    for (auto val : results) cout << val << " ";
}

int main() {
    solve();

    return EXIT_SUCCESS;
}
