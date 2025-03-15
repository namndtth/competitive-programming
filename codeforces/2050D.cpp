#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); ++i) {
        int max_pos = i;
        int max_val = stoi(s.substr(i, 1));

        // searches for a character within the next 9 positions (or until the end of the string, whichever is smaller)
        // that can be moved to position i to maximize the value of the string.
        for (int j = i + 1; j < min<int>(i + 9, s.size()); ++j) {
            if (int val = stoi(s.substr(j, 1)); val - (j - i) > max_val) {
                max_pos = j;
                max_val = val - (j - i);
            }
        }

        // insert found value in front of i
        for (int j = max_pos; j > i; --j) s[j] = s[j - 1];
        s[i] = '0' + max_val;
    }

    cout << s << endl;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }

    return EXIT_SUCCESS;
}