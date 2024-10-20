#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;

int main()
{
    freopen("data.inp", "r", stdin);

    int n; cin >> n;
    int m[MAXN] = {INT_MAX};

    vector<int> res(MAXN);
    for (int i = 1; i <= n; i++)
        cin >> m[i];

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        // tai vi tri i la dinh

        vector<int> height(MAXN, 0);

        int total_height = m[i];
        height[i] = m[i];

        for (int l = i - 1; l > 0; l--)
        {
            height[l] = min(m[l], height[l + 1]);
            total_height += height[l];
        }

        for (int r = i + 1; r <= n; r++)
        {
            height[r] = min(m[r], height[r - 1]);
            total_height += height[r];
        }

        if (ans < total_height)
        {
            ans = total_height;
            res = height;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";
    return 0;
}
