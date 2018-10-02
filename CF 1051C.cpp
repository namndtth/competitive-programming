#include <bits/stdc++.h>
using namespace std;

const int N = 109;
int n;
int a[N];
map<int, int> m;
set<int> s[2];
typedef pair<int, int> ii;


int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        m[a[i]]++;
    }
    int pos = 0;
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        if (it->second == 1)
        {
            s[pos].insert(it->first);
            pos = 1 - pos;
        }
    }

    if (s[0].size() == s[1].size())
    {
        string res(n, 'A');
        for (int i = 0; i < n; i++)
            if (s[1].count(a[i]))
                res[i] = 'B';
        cout << "YES\n";
        for (int i = 0;i < n; i++)
            cout << res[i];
        cout << "\n";
        return 0;
    }
    else
    {
        assert(int(s[0].size()) - 1 == int(s[1].size()));
        string res(n, 'A');
        for (int i = 0; i < n; i++)
            if (s[1].count(a[i]))
                res[i] = 'B';
        int id = -1;
        for (map<int, int>::iterator it = m.begin(); it != m.end();it++)
        {
            if (it->second >= 3)
            {
                id = it->first;
                break;
            }

        }
        if (id == -1)
        {
            cout << "NO" << endl;
            return 0;
        }
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == id)
                if (!flag)
                {
                    flag = true;
                    res[i] = 'B';
                }
        }
        cout << "YES\n";
        for (int i = 0;i < n; i++)
            cout << res[i];
        cout << "\n";
        return 0;
    }
    return 0;
}
