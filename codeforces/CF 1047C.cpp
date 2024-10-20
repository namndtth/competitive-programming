#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = a; i < b; i++)

const int maxn = 3e5;
int arr[maxn];
int ans[maxn];

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int n;
    cin >> n;
    FOR(i, 0, n)
    {
        cin >> arr[i];
        ans[i] = gcd(arr[i], anr[i - 1]);
    }
}
