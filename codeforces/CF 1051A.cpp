#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        int n = int(s.length());
        int i;
        int u = 0, l = 0, d = 0;
        for (i = 0; i < n; i++)
        {
            if (islower(s[i]))
                l++;
            else
                if (isupper(s[i]))
                    u++;
                else
                    d++;
        }

        if (!d && !l && !u)
            cout << s + "\n";
        else
        {
            if (d==0 && l != 0 && u != 0)
            {
                if (l >= 2)
                {
                    for (i = 0;i < n; i++)
                        if (islower(s[i]))
                        {
                            s[i] = '0';
                            break;
                        }
                }
                else
                {
                    for (i = 0;i < n; i++)
                        if (isupper(s[i]))
                        {
                            s[i] = '0';
                            break;
                        }
                }
            }
            else if (d != 0 && l==0 && u != 0)
                {
                    if (d >= 2)
                    {
                        for (i = 0;i < n; i++)
                            if (isdigit(s[i]))
                            {
                                s[i] = 'a';
                                break;
                            }
                    }
                    else
                    {
                        for (i = 0;i < n; i++)
                            if (isupper(s[i]))
                            {
                                s[i] = 'a';
                                break;
                            }
                    }
                }
            else if (d!=0 && l!=0 && u==0)
                {
                    if (d >= 2)
                    {
                        for (i = 0;i < n; i++)
                            if (isdigit(s[i]))
                            {
                                s[i] = 'A';
                                break;
                            }
                    }
                    else if (l>=2)
                    {
                        for (i = 0;i < n; i++)
                            if (islower(s[i]))
                            {
                                s[i] = 'A';
                                break;
                            }
                    }
                }
            else if (d == 0 && l == 0 && u != 0)
            {
                s[0] = '0';
                s[1] = 'a';
            }
            else if (d == 0 && l != 0 && u == 0)
            {
                s[0] = '0';
                s[1] = 'A';
            }
            else if (d != 0 && l == 0 && u == 0)
            {
                s[0] = 'a';
                s[1] = 'A';
            }
            cout << s + "\n";
        }
    }
}
