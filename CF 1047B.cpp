#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main()
{
    int n;
    cin >> n;
    ii maxx(-1, -1);
    ii cord;
    int i;
    for (i = 0; i < n; i++)
    {
        cin >> cord.first >> cord.second;
        if (cord.first + cord.second > maxx.first + maxx.second)
        {
            maxx.first = cord.first;
            maxx.second = cord.second;
        }
    }
    cout << maxx.first + maxx.second;
    return 0;
}
