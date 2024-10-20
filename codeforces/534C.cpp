#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a;
    cin >> n >> a;
    vector<int> d(n);
    vector<pair<int, int>> minmax;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
        if (i != 0)
            minmax.emplace_back(minmax[i - 1].first + 1, minmax[i - 1].second + d[i]);
        else
            minmax.emplace_back(1, d[0]);
    }

    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        if (a - minmax[i].first)
            if (a - minmax[i].second < d[i])

    }
}
