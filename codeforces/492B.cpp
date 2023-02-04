#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#define ll long long
using namespace std;
int main()
{
    ll num_latterns, length;
    cin >> num_latterns >> length;
    vector<int> pos_latterns(num_latterns);
    for (int i = 0; i < num_latterns; i++)
        cin >> pos_latterns[i];
    sort(pos_latterns.begin(), pos_latterns.end(), less<ll>());
    ll max_dist = 2 * max<ll>(pos_latterns[0], length - pos_latterns[num_latterns - 1]);
    for (int i = 1; i < num_latterns; i++)
        max_dist = max<ll>(max_dist, pos_latterns[i] - pos_latterns[i - 1]);
    cout << fixed << setprecision(10) << max_dist / 2.0;
    return 0;
}