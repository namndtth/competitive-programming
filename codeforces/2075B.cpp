#include <bits/stdc++.h>
using namespace std;

// if k >= 2 => k + 1 largest element by choosing:
//  pick p1, p2, pk+1
//  leave out p2 as last painted element and pick the rest
// else
// max(a[0] + max elem of rests, a[n - 1] + max elem of rests)

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    long long ans{0};
    if (k == 1) {
        ans = a[0] + *max_element(a.begin() + 1, a.end());
        ans = max<long long>(ans, *max_element(a.begin(), a.end() - 1) + a[n - 1]);
    } else {
        sort(a.begin(), a.end(), std::greater<int>());
        ans = std::accumulate(a.begin(), a.begin() + k + 1, 0ll);
    }
    cout << ans << endl;
}
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return EXIT_SUCCESS;
}