#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    map<int, int> mp;
    for (int i = 1; i <= 9; i++)
    {
        int x;
        cin >> x;
        mp.emplace(i, x);
    }

    int i{0};
    while (i < n && s[i] - '0' >= mp[s[i] - '0'])
    {
        i++;
    }


    while (i < n && s[i] - '0' <= mp[s[i] - '0'])
    {
        s[i] = mp[s[i] - '0'] + '0';
        i++;
    }

    cout << s << endl;

    return EXIT_SUCCESS;
}
