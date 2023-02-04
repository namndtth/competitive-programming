#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, int> freq;
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int beauty; cin >> beauty;
        freq[beauty]++;
    }
    pair<int, int> min_pair = *freq.begin();
    pair<int, int> max_pair = *freq.rbegin();

    if (freq.size() == 1)
    {
        if (min_pair.second == 2)
            cout << 0 << " " << 1 << endl;
        else
            cout << 0 << " " << 1LL * min_pair.second * (min_pair.second - 1) / 2 << endl;
    }
    else
        cout << max_pair.first - min_pair.first << " " << 1LL * min_pair.second * max_pair.second << endl;
    return 0;
}
