#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    n = n - 2;
    if (n % 3 == 0)
        cout << "1 " << "2 " << n - 1;
    else
        cout << "1 " << "1 " << n;
    return 0;
}
