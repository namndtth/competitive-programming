#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> dollars = {100, 20, 10, 5, 1};
    int ans = 0;
    for (int i = 0; i < dollars.size(); i++)
    {
        ans += n / dollars[i];
        n = n % dollars[i];
    }
    cout << ans << endl;
    return 0;
}
