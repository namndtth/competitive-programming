#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int &val : a) cin >> val;
    for (int &val : b) cin >> val;

    sort(b.begin(), b.end());

    bool is_non_desc{true};
    int i = n - 1, j = m - 1;
    while (i >= 0 && j >= 0) {
        if (a[i] < b[j] - a[i]) {
            a[i] = b[j] - a[i];
            --j;
        }
        if (a[i] > a[i + 1]) {
            is_non_desc = false;
            break;
        }
        --i;
    }
    cout << (is_non_desc ? "YES" : "NO") << endl;
}

int main() {
    solve();
    return EXIT_SUCCESS;
}