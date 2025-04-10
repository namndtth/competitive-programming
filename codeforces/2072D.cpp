#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &val : a) cin >> val;

    // Count number of elements that greater and less than a[i]
    // When insert a[i] into new position j
    // Greater becomes less => less - greater is the number of inversion we've reduced
    // Find max
    int mx{INT_MIN};
    pair<int, int> ans;
    for (int i = 0; i < n - 1; ++i) {
        int greater{0}, less{0};
        for (int j = i + 1; j < n; ++j) {
            if (a[i] < a[j]) ++greater;
            if (a[i] > a[j]) ++less;
            if (less > greater && mx < less - greater) {
                mx = less - greater;
                ans.first = i, ans.second = j;
            }
        }
    }

    cout << ans.first + 1 << " " << ans.second + 1 << endl;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
    return EXIT_SUCCESS;
}