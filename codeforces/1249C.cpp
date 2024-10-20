#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void print_array(const vector<ll>& arr)
{
    for (ll x: arr) cout << x;
}

vector<ll> convert_base_10_to_3(ll x)
{
    vector<ll> result;

    while (x > 0)
    {
        result.push_back(x % 3);
        x /= 3;
    }

    std::reverse(result.begin(), result.end());

    return result;
}

long double convert_base_3_to_10(const vector<ll>& base3)
{
    long double result{0};

    for (int i = 0; i < base3.size(); i++)
        result += base3[i] * pow<long double>(3, base3.size() - 1 - i);

    return result;
}


bool pred(ll x)
{
    return x == 0 || x == 1;
}

void solve()
{
    ll n;
    cin >> n;

    if (auto base3{convert_base_10_to_3(n)}; all_of(base3.begin(), base3.end(), pred))
        cout << n << endl;
    else
    {
        base3.insert(base3.begin(), 0);

        if (auto pos = find_if(base3.begin(), base3.end(), [](ll x) { return x > 1; }); pos != base3.end())
        {
            ll pos_zero{0};
            for (ll i = pos - base3.begin(); i >= 0; i--)
            {
                if (base3[i] == 0)
                {
                    pos_zero = i;
                    break;
                }
            }

            base3[pos_zero] = 1;
            std::fill(base3.begin() + pos_zero + 1, base3.end(), 0);
        }

        cout << setprecision(20) << convert_base_3_to_10(base3) << endl;
    }
}

int main()
{
    ll tc;
    cin >> tc;

    while (tc--)
    {
        solve();
    }

    return EXIT_SUCCESS;
}
