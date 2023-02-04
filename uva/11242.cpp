#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
    int f, r;
    vector<float> front, rear;
    vector<float> drive_ratio;
    float ans;
    while (scanf("%d", &f))
    {
        if (f == 0)
            break;

        scanf("%d", &r);

        front.resize(f);
        rear.resize(r);

        drive_ratio.clear();

        ans = INT_MIN;

        for (int i = 0; i < f; i++)
            cin >> front[i];

        for (int i = 0; i < r; i++)
            cin >> rear[i];

        // angular velocity: n/m, n is the number of teeth on the rear, m ... front
        for (int i = 0; i < r ; i++)
        {
            for (int j = 0; j < f; j++)
            {
                float ratio = rear[i] / front[j];
                drive_ratio.push_back(ratio);
            }
        }
        sort(drive_ratio.begin(), drive_ratio.end());

        for (int i = 1; i < (int)drive_ratio.size(); i++)
        {
            ans = max(ans, drive_ratio[i] / drive_ratio[i - 1]);
        }
        printf("%.2f\n", ans);
    }
}
