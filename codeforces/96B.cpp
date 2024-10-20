#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll to_ll(const vector<int>& v)
{
    ll res{0};
    for (int i = v.size() - 1; i >= 0; --i) res += v[i] * pow<ll>(10ll, i);

    return res;
}

set<ll> prebuild()
{
    set<ll> result;
    for (int i = 2; i <= 10; i += 2)
    {
        vector<int> num{};
        for (int j = 0; j < i; j++)
        {
            if (j < i / 2) num.push_back(4);
            else num.push_back(7);
        }

        do
        {
            result.insert(to_ll(num));
        } while (next_permutation(num.begin(), num.end()));
    }

    return result;
}

void solve()
{
    ll n;
    cin >> n;

    auto lucky_numbers{prebuild()};
    cout << *lucky_numbers.lower_bound(n) << endl;
}

int main()
{
    solve();

    return EXIT_SUCCESS;
}
