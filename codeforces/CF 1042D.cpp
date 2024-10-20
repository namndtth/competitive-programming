#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < b;i++)
using namespace std;
const int N = 200 * 1000 + 13;
int n;
long long T;
int a[N];
int f[N];

void upd(int x)
{

    for (int i = x; i < N; i |= i + 1)
    {
        ++f[i];

    }

}
int get(int x)
{
    int res = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
        res += f[i];
    return res;
}
int main()
{
    cin >> n >> T;
    FOR(i, 0, n)
        cin >> a[i];
    vector<long long> sums(1, 0ll);
    long long pr = 0;
    FOR(i, 0, n)
    {
        pr += a[i];
        sums.push_back(pr);
    }
    sort(sums.begin(), sums.end());

    sums.resize(unique(sums.begin(), sums.end()) - sums.begin());

    long long ans = 0;
    pr = 0;
    upd(lower_bound(sums.begin(), sums.end(), 0ll) - sums.begin());

    FOR(i, 0, n)
    {
        pr += a[i];
        int npos = upper_bound(sums.begin(), sums.end(), pr - T) - sums.begin();
        ans += (i + 1 - get(npos - 1));
        int k = lower_bound(sums.begin(), sums.end(), pr) - sums.begin();
        upd(k);
    }
    cout << ans;
    return 0;
}


