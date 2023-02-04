#include <bits/stdc++.h>
using namespace std;

const int maxn = 2 * 1e5 + 5;
const int maxm = 1e9;
bool flag[maxn];
typedef pair <int, int > ii;
vector<ii> vii;

bool cmp(ii x, ii y)
{
    return (x.first <= y.first);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int i, j;
    int n, m, d;
    int ans[maxn], a[maxn];
    memset(ans, 0, sizeof ans);
    memset(flag, false, sizeof flag);
    cin >> n >> m >> d; d++;
    for (i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vii.push_back(ii(x, i));
    }
    sort(vii.begin(), vii.end());
    int day = 1;
    int t = 0;
    for (i = 0 ; i < n ; i++)
    {
        t = 0 ;
        for (j = i; j < n; j++)
        {
            if (vii[i].first > t && !flag[t])
            {
                ans[vii[i].second] = day;
                flag[vii[i].second] = true;
                t += d;
            }
        }
        day++;
    }
    for (i = 0; i < n; i++)
        cout << ans[i];
    return 0;
}
