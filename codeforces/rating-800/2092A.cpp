#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& val : a) cin >> val;

    auto [min, max] = std::minmax_element(a.begin(), a.end());
    cout << *max - *min << endl;
}
int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }

    return EXIT_SUCCESS;
}