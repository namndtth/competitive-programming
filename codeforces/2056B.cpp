#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<string> adj_mat(n);
    for (string& st : adj_mat) cin >> st;

    // position of value x in permutation is determined by the total number of values that:
    // are greater and lie before x
    // are smaller and lie after x
    vector<int> p(n);
    for (int i /*x*/ = 0; i < n; ++i) {
        int cnt{0};

        for (int j = 0; j < n; ++j) {
            if ((j > i && adj_mat[i][j] == '0' /*greater and lie before x*/ ) || (j < i && adj_mat[i][j] == '1' /*smaller and lie after x*/ )) {
                cnt++;
            }
        }

        p[cnt] = i + 1;
    }
    for (int x : p) cout << x << " ";
    cout << endl;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }

    return EXIT_SUCCESS;
}