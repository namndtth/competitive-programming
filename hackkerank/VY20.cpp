#include <bits/stdc++.h>
using namespace std;

int64_t p[27], x, y;
int h = 50003;
string s;
int main()
{

    cin >> s;
    int n = s.size();
    p[0] = 1;
    int i, q;
    vector<int64_t> f(n + 1, 0);
    for (i = 1; i <= 26; i++)
        p[i] = p[i - 1] * h;
    for (i = 1; i <= n; i++)
        f[i] = f[i - 1] + p[s[i - 1] - 96];
    cin >> q;
    for (i = 0; i < q; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        x = f[b] - f[a - 1];
        y = f[d] - f[c - 1];
        (x == y) ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}
