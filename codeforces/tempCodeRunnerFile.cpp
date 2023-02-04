#include <bits/stdc++.h>
#define ll long long
#define MAXN (int)2e5
using namespace std;

pair<int, int> alt_subseq(vector<int> a, int n, int start, int sign)
{
    while (a[start] * sign < 0 && start < n)
        start++;
    int end = start;
    while (a[end] * sign > 0 && end < n)
        end++;
    return make_pair(start, end);
}
pair<int, ll> begin_with(int sign, vector<int> a, int n)
{
    int i = 0, length = 0;
    ll res = 0;
    while (i < n)
    {
        length++;
        pair<int, int> satisfy_el = alt_subseq(a, n, i, sign);
        int fi = satisfy_el.first, la = satisfy_el.second;
        res += *max_element(a.begin() + fi, a.begin() + la);
        i = la;
        sign *= -1;
    }
    return make_pair(length, res);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        pair<int, ll> pos = begin_with(1, a, n);
        pair<int, ll> neg = begin_with(-1, a, n);
        if (pos.first > neg.first)
            cout << pos.second << endl;
        else if (pos.first < neg.first)
            cout << neg.second << endl;
        else
            cout << max(pos.second, neg.second) << endl;
    }
    return 0;
}