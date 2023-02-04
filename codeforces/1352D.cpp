#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("data.inp", "r", stdin);

    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> a(n);
        vector<int> tot(n + 1);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            tot[i + 1] = tot[i] + a[i];
        }

        // first move

        int prev = tot[1];
        int l = 2, r = n;
        int turn = 1;
        int found = 0;
        int num_move = 1;
        while (!found)
        {

            // Bob's move

            if (turn)
            {
                int j = r;
                int total = 0;
                while (!found)
                {
                    total = tot[r] - tot[j - 1];

                    if (j <= l)
                    {
                        found = j;
                        break;
                    }
                    else if (total > prev)
                    {
                        r = j;
                        prev = total;
                        break;
                    }
                    j--;
                }
                turn ^= 1;
            }
            // Alice's move
            else if (!turn)
            {
                int i = l;
                int total = 0;
                while (!found)
                {
                    total = tot[i] - tot[l - 1];
                    if (i >= r)
                    {
                        found = i;
                        break;
                    }
                    else if (total > prev)
                    {
                        l = i;
                        prev = total;
                        break;
                    }
                    i++;
                }
                turn ^= 1;
            }
            num_move++;
        }
        cout << num_move << " " << tot[found - 1] << " " << tot[n] - tot[found - 1] << endl;
    }
    return 0;
}
