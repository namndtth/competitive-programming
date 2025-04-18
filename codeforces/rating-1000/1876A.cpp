#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n, p;
    cin >> n >> p;

    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i].second;
    for (int i = 0; i < n; ++i) cin >> v[i].first;

    sort(v.begin(), v.end());

    queue<pair<ll, ll>> q;
    q.push(v[0]);

    ll cost{p};

    int i{1};
    while (i < n && !q.empty()) {
        const auto [announcement_cost, num_residents] = q.front(); q.pop();
        if (announcement_cost >= p) break;

        for (int j = 0; j < num_residents && i < n; ++j, ++i) {
            q.push(v[i]);
            cost += announcement_cost;
        }
    }

    cout << cost + (n - i) * p << endl;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }

    return EXIT_SUCCESS;
}
