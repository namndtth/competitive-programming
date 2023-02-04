#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int cntneg = 0;
    int cntzero = 0;
    vector<int> used(n);
    int pos = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            used[i] = 1;
            cntzero++;
        }
        if (a[i] < 0)
        {
            cntneg++;
            if (pos == -1 || abs(a[pos]) > abs(a[i]))
                pos = i;
        }
    }
    if (cntneg & 1)
        used[pos] = 1;

    if (cntzero == n || (cntzero == n - 1 && cntneg == 1))
    {
        for (int i = 0; i < n - 1; i++)
            printf("1 %d %d\n", i + 1, i + 2);
        return 0;
    }
    int lst = -1;
    for (int i = 0; i < n; i++)
    {
        if (used[i])
        {
            if (lst != -1)
                printf("1 %d %d\n", lst + 1, i + 1);
            lst = i;
        }
    }

    if (lst != -1)
        printf("2 %d\n", lst + 1);

    lst = -1;
    for (int i = 0; i < n; i++)
    {
        if (!used[i])
        {
            if (lst != -1)
                printf("1 %d %d\n", lst + 1, i + 1);
            lst = i;
        }
    }
    return 0;
}
