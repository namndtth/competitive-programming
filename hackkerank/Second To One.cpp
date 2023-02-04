#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 5;

int main()
{
    set<int> arr;
    int n, i, s;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> s;
        if (arr.find(s) == arr.end())
            arr.insert(s);
    }
    int rank = 1;
    for (set<int>::reverse_iterator rit = arr.rbegin(); rit != arr.rend(); rit++)
    {
        if (rank == 2)
        {
            cout << (*rit);
            break;
        }
        rank++;
    }
    return 0;
}
