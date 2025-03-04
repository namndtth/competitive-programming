#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        string s;
        cin >> s;
        cout << count(s.begin(), s.end(), '1') << endl;
    }
    return EXIT_SUCCESS;
}
