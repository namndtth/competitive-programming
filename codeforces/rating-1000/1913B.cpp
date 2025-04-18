#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    int zero = count_if(s.begin(), s.end(), [](char c) { return c == '0'; });
    int one = s.length() - zero;

    if (zero == one) {
        cout << 0 << endl;
        return;
    }

    int ans{0};
    if (zero < one) {
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '1' && zero == 0) {
                ans = s.length() - i;
                break;
            }

            if (s[i] == '1') --zero;
        }
    } else {
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '0' && one == 0) {
                ans = s.length() - i;
                break;
            }
            if (s[i] == '0') --one;
        }
    }

    cout << (zero + one == 0 ? 0 : ans) << endl;
}

void tutorial_solution() {
    string s;
    cin >> s;

    map<char, int> cnt;
    cnt[0] = count_if(s.begin(), s.end(), [](char c) { return c == '0'; });
    cnt[1] = s.length() - cnt[0];

    if (cnt[0] == cnt[1]) {
        cout << 0 << endl;
    } else {
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (cnt[1 - stoi(s.substr(i, 1))] == 0) {
                cout << n - i << endl;
                return;
            }
            --cnt[1 - stoi(s.substr(i, 1))];
        }
    }
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        tutorial_solution();
    }

    return EXIT_SUCCESS;
}
