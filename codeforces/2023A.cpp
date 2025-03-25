#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<pair<ll, ll>> a(n);
    for (auto& [fst, snd] : a) cin >> fst >> snd;

    sort(a.begin(), a.end(), [](const pair<ll, ll>& p1, const pair<ll, ll>& p2) {
        pair p3{min(p1.first, p1.second), max(p1.first, p1.second)};
        pair p4{min(p2.first, p2.second), max(p2.first, p2.second)};
        return p3 < p4;
    });

    for (const auto& [fst, snd] : a) cout << fst << " " << snd << " ";
    cout << endl;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }

    return EXIT_SUCCESS;
}