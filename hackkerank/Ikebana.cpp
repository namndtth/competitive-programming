#define FOR(i, a, b) for (int i = int(a); i < int(b); i++)
#include <bits/stdc++.h>
using namespace std;
const int64_t p = 1e9 + 7;
int n;
int main()
{
    cin >> n;
    vector<int64_t> h(n), fl(n), fr(n+1);
    vector<int> a(n), ans;
    h[0] = 1;
    FOR(i, 1, n)
        h[i] = h[i - 1] * p;
    FOR(i, 0, n)
        cin >> a[i];
    fl[0] = a[0]; fr[n - 1] = a[n - 1]; fr[n] = 0;
    FOR(i, 1, n)
        fl[i] = fl[i - 1] * p + a[i];
    for (int i = n - 2; i >= 0; i--)
        fr[i] = fr[i + 1] * p + a[i];
    ans.push_back(n);
    FOR(i, 0, n/2)
        if ((fr[i + 1] - fr[2*i + 2]*h[i + 1]) == fl[i])
            ans.push_back(n - i - 1);
    cout << ans.size() << "\n";
    FOR(i, 0, ans.size())
        cout << ans[i] << " ";
    return 0;
}
