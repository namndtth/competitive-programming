//
// Created by NAMND on 5/6/2023.
//
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> matchboxes(m);
    for (int i = 0; i < m; i++)
        cin >> matchboxes[i].first >> matchboxes[i].second;

    sort(matchboxes.begin(), matchboxes.end(), [](pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    });

    int ans = 0;
    for (auto& item: matchboxes)
    {
        if (n > item.first)
        {
            ans += item.first * item.second;
            n -= item.first;
        }
        else if (n != 0)
        {
            ans += n * item.second;
            n = 0;
        }
    }
    cout << ans << endl;
}


int main()
{
    solve();
    return EXIT_SUCCESS;
}