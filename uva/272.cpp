#include <bits/stdc++.h>
using namespace std;

vector<string> strs;

int main()
{
    strs.clear();

    freopen("data.inp", "r", stdin);
    string str;

    while (getline(cin, str))
    {
        strs.push_back(str);
    }
    int sw = 0;
    for (int i = 0; i < strs.size(); i++)
        for (int j = 0; j < strs[i].size(); j++)
            if (sw == 0 && strs[i][j] == '"')
            {
                strs[i].replace(j, 1, "``");
                sw = 1 - sw;
            }
            else if (sw == 1 && strs[i][j] == '"')
            {
                strs[i].replace(j, 1, "''");
                sw = 1 - sw;
            }

    for (auto v: strs)
        cout << v << endl;

    return 0;
}
