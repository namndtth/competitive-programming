#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    string st;
    cin >> st;

    // ....sp(ps)........
    // `a` is first permutation part, `b` is second permutation part
    // `b` must contain `a`, but it doesn't => contradiction
    // Cases satisfy the condition above:
    // First character or last character is allowed to different from the rest
    bool ok = all_of(st.begin(), st.end() - 1, [](char x) { return x == 's' | x == '.'; }) |
              all_of(st.begin() + 1, st.end(), [](char x) { return x == 'p' || x == '.'; });

    cout << (ok ? "YES" : "NO") << endl;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }

    return EXIT_SUCCESS;
}