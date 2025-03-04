#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int sum_up(vi b)
{
    int total = 0;
    for (auto e: b)
        total += e;
    return total;
}

vi calculate_b(vi a, int n)
{
    vi b;
    b.assign(n - 1, 0);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            b[i - 1] += (a[j] <= a[i] ? 1 : 0);
        }
    }
    return b;
}

int main()
{
    // freopen("data.inp", "r", stdin);
    // freopen("data.out", "w", stdout);
    
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, x;
        
        cin >> n;
        vi a;

        for (int i = 0; i < n; i++)
        {
            cin >> x;
            a.push_back(x);
        }

        vi b = calculate_b(a, n);
        cout << sum_up(b) << endl;
    }
    return 0;
}