#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> base_converter(ll base, ll n)
{
    vector<ll> res;
    while (n)
    {
        ll rmd = n % base;
        n /= base;
        res.push_back(rmd);
    }
    return res;
}
ll reverse_converter(vector<ll> converted)
{
    ll total = 0;
    for (int i = 0; i < (int)converted.size(); i++)
        if (converted[i] != 0)
            total += pow(3, i);
    return total;
}
int main()
{
    freopen("data.inp", "r", stdin);

    ll tc; cin >> tc;
    ll base = 3;

    while (tc--)
    {
        ll n; cin >> n;

        vector<ll> converted = base_converter(base, n);
        int m = (int)converted.size();
        converted.push_back(0);

        for (int i = m - 1; i >= 0; i--)
        {
            if (converted[i] == 2)
            {
                for (int j = i + 1; j < m + 1; j++)
                {

                    if (converted[j] == 0)
                    {
                        converted[j] = 1;
                        for (int k = j - 1; k >= 0; k--)
                            converted[k] = 0;
                        break;
                    }
                }
                break;
            }
        }

        ll reverted = reverse_converter(converted);

        cout << reverted << endl;
    }
}
