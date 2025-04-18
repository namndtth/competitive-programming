#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<vector<ll>> a(n);
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        a[i].resize(m);
        for (ll &val : a[i]) cin >> val;
    }

    vector<ll> nth_elems(n);
    ll min_elem{LLONG_MAX};
    for (int i = 0; i < n; ++i) {
        sort(a[i].begin(), a[i].end());
        nth_elems[i] = a[i][1];
        min_elem = min(min_elem, a[i][0]);
    }
    auto pos = distance(nth_elems.begin(), min_element(nth_elems.begin(), nth_elems.end()));
    ll result = accumulate(nth_elems.begin(), nth_elems.end(), 0ll) - nth_elems[pos] + min_elem;
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
