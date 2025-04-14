#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    vector<int> a(n); for (int &val : a) cin>> val;

    int result{0};
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            int j = i;
            while (j < n && a[j] == 0) j++;
            result = max(result, j - i);
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
