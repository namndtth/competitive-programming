#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<ll> a(n);
    for (auto &elem: a) cin >> elem;

    ll sum = accumulate(a.begin(), a.end(), 0ll);
    cout << max<ll>(ceil(sum * 1.0 / x), *max_element(a.begin(), a.end())) << endl;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }

    return EXIT_SUCCESS;
}