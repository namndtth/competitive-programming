#include <iostream>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string t;
        cin >> t;
        int cnt = 0;
        for (int i = 0; i < (int)t.size(); i++)
            if (t[i] == '0')
                cnt++;
        if (cnt == 0 || cnt == (int)t.size())
            cout << t << endl;
        else
        {
            for (int i = 0; i < (int)t.size(); i++)
            {
                cout << "01";
            }
            cout << endl;
        }
    }
    return 0;
}
