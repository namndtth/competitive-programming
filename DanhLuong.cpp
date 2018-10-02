#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long ans = INT_MAX;

    for (int i = -1;i <= 1;i += 2)
    {
        long long sum = 0;
        vector<int> tmp(n);
        for (int j = 0; j < n; j+=2)
            tmp[j] = a[j] + k * i;
        nth_element(tmp.begin(), tmp.begin() + tmp.size()/2, tmp.end());
        int val = tmp[tmp.size()/2];
        for (int num : tmp)
            sum+= abs(val - num);
        ans = min(ans, sum);
    }
    cout << ans;
    return 0;
}

