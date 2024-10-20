#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 1005;
const ll M = 16;

struct data
{
    int c1, c2, val, idx;
    bool operator<(data &b)
    {
        return val < b.val;
    }
};

ll n, sum, ans = 0;
bool ban[N], vis[N];
ll cnt[M], taken[M];
vector<data> g[M], edges[M];
vector<ll> path;
ll compress(ll c1, ll c2)
{
    if (c1 > c2)
        swap(c1, c2);
    return c1 * 4 + c2;
}
