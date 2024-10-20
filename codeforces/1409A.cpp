#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc; cin >> tc;
    while (tc--)
    {
        long long a, b;
        cin >> a >> b;
        cout << (abs(b - a) + 9) / 10 << "\n";
    }
    return 0;
}
