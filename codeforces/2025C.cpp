#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<ll> a;
    map<ll, ll> freq;
    for (int i = 0; i < n; ++i) {
        ll x; cin >> x;
        if (freq.find(x) == freq.end()) a.push_back(x);
        freq[x]++;
    }

    sort(a.begin(), a.end());

    auto prev = a.begin(), cur = next(prev);
    ll sum = freq[*prev], ans = sum;
    int cnt = 1;
    while (cur != a.end()) {
        if (*cur - *prev > 1) {
            cnt = 1;
            sum = freq[*cur];
        } else if (*cur - *prev <= 1 && cnt < k) {
            sum += freq[*cur];
            ++cnt;
        } else {
            sum -= freq[*std::prev(cur, k)];
            sum += freq[*cur];
        }

        ++prev, ++cur;

        ans = max(ans, sum);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }

    return EXIT_SUCCESS;
}