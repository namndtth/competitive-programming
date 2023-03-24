#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    // freopen("../input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int num_monsters, initial_damage;
        cin >> num_monsters >> initial_damage;

        int h[num_monsters], p[num_monsters];
        for (int i = 0; i < num_monsters; i++)
            cin >> h[i];
        for (int i = 0; i < num_monsters; i++)
            cin >> p[i];

        ll dmg_deal = 0;

        for (int i = 0; i < num_monsters; i++)
        {
            if (initial_damage <= 0)
                break;
            if (h[i] <= dmg_deal)
                continue;

            dmg_deal += initial_damage;
            initial_damage -= p[i];
        }
        if (h[num_monsters - 1] <= dmg_deal)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}