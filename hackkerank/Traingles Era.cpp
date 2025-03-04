#include <bits/stdc++.h>
using namespace std;

const float EPS = 0.00000001;
const int N = 100 + 5;
int main()
{
    int n;
    float s[N];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        if (s[i] - EPS < 0.5)
            cout << "N";
        else
        {
            if (s[i] * 2 - EPS <= floor(s[i] * 2))
                cout << "Y";
            else
                cout << "N";
        }
    }
    return 0;
}
