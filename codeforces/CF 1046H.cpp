#define FOR(i, a, b) for (int i = a; i < b; i++)
#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 5;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    map<char, int> cnt;
    vector<string> s;
    string t;
    int n, ans = 0;
    cin >> n;
    FOR(i, 0, n)
    {
        cin >> t;
        s.push_back(t);
    }
    FOR(i, 0, n - 1)
    {
        FOR(j, i + 1, n)
        {
            cnt.clear();
            t = "";
            int n1 = 0, n3 = 0;
            t = s[i] + s[j];
            int len = t.length();
            FOR(k, 0, len)
                cnt[t[k]]++;

            for (map<char, int>::iterator it = cnt.begin(); it != cnt.end(); it++)
            {
                if (it->second == 1)
                    n1++;
                else
                    if (it->second % 2 != 0)
                        n3++;
            }
            if ((n1 == 1 && n3 == 0) || (n1 == 0 && n3 == 1) || (n1 == 0 && n3 == 0))
                ans++;
        }
    }
    cout << ans;
    return 0;
}
