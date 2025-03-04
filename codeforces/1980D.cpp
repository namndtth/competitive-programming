#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n), b(n - 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i > 0) {
      b[i - 1] = gcd(a[i], a[i - 1]);
    }
  }
}

int main() {}