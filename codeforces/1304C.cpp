#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("data.inp", "r", stdin);

    int tc; cin >> tc;

    while (tc--)
    {
        int n, m; cin >> n >> m;
        vector<pair<int, int>> reserved_customers;
        vector<int> lower, upper;
        int t, l, h;
        bool is_satisfied = true;
        for (int i = 0; i < n; i++)
        {
            cin >> t >> l >> h;

            lower.push_back(l);
            upper.push_back(h);
            reserved_customers.push_back(make_pair(t, i));
        }

        sort(reserved_customers.begin(), reserved_customers.end());

        int interval_time, index;
        int min_temp, max_temp;
        for (int i = 0; i < n; i++)
        {
            index = reserved_customers[i].second;
            if (i == 0)
            {
                interval_time = reserved_customers[i].first - 0;
                min_temp = m - interval_time;
                max_temp = m + interval_time;
            }
            else
            {
                interval_time = reserved_customers[i].first - reserved_customers[i - 1].first;
                min_temp -= interval_time;
                max_temp += interval_time;
            }
            if (max_temp < lower[index] || min_temp > upper[index])
            {
                cout << "NO\n";
                is_satisfied = false;
                break;
            }
            min_temp = max(min_temp, lower[i]);
            max_temp = min(max_temp, upper[i]);
        }
        if (is_satisfied)
            cout << "YES\n";
    }
    return 0;
}
