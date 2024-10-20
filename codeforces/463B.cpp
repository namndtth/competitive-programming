//
// Created by NAMND on 5/6/2023.
//
#include <bits/stdc++.h>

using namespace std;

int consume(vector<int>& h, int e)
{
    int smallest = 1e9;
    int consumption = 0;
    h[0] = e;
    for (int i = 0; i < h.size() - 1; i++)
    {
        consumption += h[i] - h[i + 1];
        smallest = min(smallest, consumption);
    }
    return smallest;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> h[i];

    int low = 0, high = 1e9;
    int mid;
    while (true)
    {
        mid = low + (high - low) / 2;
        int smallest = consume(h, mid);
        if (smallest == 0)
            break;
        if (smallest > 0)
            high = mid;
        else
            low = mid;
    }
    cout << mid << endl;
}

int main()
{
    solve();
    return EXIT_SUCCESS;
}