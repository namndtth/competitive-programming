#include <bits/stdc++.h>
using namespace std;

vector<int> pre_cal_num_segment(vector<int> a)
{
    int i = 0, n = a.size();

    vector<int> res(n + 1);

    while (i < n)
    {
        if (a[i] == 0)
        {
            i++;
            continue;
        }

        int j = i;

        while (j < n && a[j] == 1)
            j++;

        for (int len = 1; len <= j - i; len++)
            res[len] += j - i - len + 1;

        i = j;
    }
    return res;
}

int main()
{
    // freopen("data.inp", "r", stdin);
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n), b(m);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < m; i++)
        cin >> b[i];

    vector<int> ao = pre_cal_num_segment(a);
    vector<int> bo = pre_cal_num_segment(b);

    long long ans = 0;

    for (int i = 1; i < ao.size(); i++)
    {
        if (k % i == 0 && k / i <= m)
            ans += ao[i] * bo[k / i];
    }
    cout << ans << endl;
    return 0;
}
