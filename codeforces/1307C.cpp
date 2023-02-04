#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll arr1[26], arr2[26][26];

int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        int c = s[i] - 'a';
        for (int j = 0; j < 26; j++)
            arr2[j][c] += arr1[j];
        arr1[c]++;
    }

    ll ans = 0;
    for (int i = 0; i < 26; i++)
        ans = max(ans, arr1[i]);

    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
            // ans = max(ans, arr2[i][j]);
            cout << arr2[i][j] << " ";
        cout << endl;
    }

    cout << ans << endl;
    return 0;
}
