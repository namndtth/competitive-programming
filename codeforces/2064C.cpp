/**
 * Initializes two vectors pre_pos and suf_neg to store prefix sums of positive values and suffix sums of negative
 * values, respectively. If a[i] < 0, it deletes the suffix, creating a suffix array meaning that a[i] is the leftmost
 * element. If a[i] > 0, it deletes the prefix, creating a prefix array meaning that a[i] is the rightmost element. we
 * only need to check all n+1 ways to split the array into a prefix and suffix and take the maximum across them all
 * which is easy to do in O(n)
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (ll &val : a) cin >> val;

    a.insert(a.begin(), 0);
    a.insert(a.end(), 0);

    vector<ll> pre_pos(a.size(), 0), suf_neg(a.size(), 0);
    partial_sum(a.begin(), a.end(), pre_pos.begin(), [](ll total, ll val) { return val > 0 ? total + val : total; });
    partial_sum(a.rbegin(), a.rend(), suf_neg.rbegin(),
                [](ll total, ll val) { return val < 0 ? total + abs(val) : total; });

    ll ans{0};
    for (int i = 1; i <= n; i++) {
        ans = a[i] > 0 ? max(ans, pre_pos[i] + suf_neg[i + 1]) : max(ans, pre_pos[i - 1] + suf_neg[i]);
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