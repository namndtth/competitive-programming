#include <bits/stdc++.h>
using namespace std;

vector<bool> compute_sieve_eratosthenes() {
    vector results(1e7 + 10, true);
    results[0] = false, results[1] = false;

    for (int i = 2; i <= 1e7; ++i) {
        if (results[i]) {
            for (int j = 2 * i; j <= 1e7; j += i) {
                results[j] = false;
            }
        }
    }

    return results;
}

// a = gcd(a, b).x
// b = gcd(a, b).y
// lcm / gcd = a * b / gcd^2 = prime number
// => gcd.x.gcd.b / gcd.gcd = pn => x.y = prime
// a < b => x = 1, y = prime
// replace 1 <= a < b <= n => 1 <= gcd < gcd.y <= n
// number of pairs with y = prime number up to n
// ans += n / y

void solve(const vector<bool>& sieve_eratosthenes) {
    int n;
    cin >> n;

    long long ans{0};
    for (int y = 2; y <= n; ++y) {
        if (sieve_eratosthenes[y]) {
            ans += n / y;
        }
    }

    cout << ans << endl;
}

int main() {
    auto sieve_eratosthenes = compute_sieve_eratosthenes();

int tc;
    cin >> tc;

    while (tc--) {
        solve(sieve_eratosthenes);
    }
    return EXIT_SUCCESS;
}