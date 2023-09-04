//
// Created by NAMND on 5/6/2023.
//
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, a;
    cin >> n >> a;
    vector<int> t(n);
    for (int& item: t)
        cin >> item;

    int ans = t[--a];
    int l = a, r = a;
    while (l >= 0 || r < n)
    {
        l--, r++;
        if (l >= 0 && r < n && t[l] && t[r])
            ans += 2;
        else if ((l < 0 && r < n && t[r]) || (l >= 0 && r >= n && t[l]))
            ans++;
    }
    cout << ans << endl;
}


int main()
{
    solve();
    return EXIT_SUCCESS;
}