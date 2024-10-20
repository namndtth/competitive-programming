#include <bits/stdc++.h>
using namespace std;

set<char> dict;

int main()
{
    string st;
    cin >> st;
    for (int i = 0; i < int(st.size()); i++)
    {
        dict.insert(st[i]);
    }
    if (dict.size() % 2 == 0)
        cout << "CHAT WITH HER!" << endl;
    else
        cout << "IGNORE HIM!" << endl;
    return 0;
}
