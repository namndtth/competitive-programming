#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    set<int> st;
    for (int i = 1; i <= n; i++) st.insert(i);

    vector<int> rem;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if (st.find(x) != st.end())
            st.erase(x);
        else
            rem.push_back(x);
    }

    sort(rem.begin(), rem.end(), greater<int>());

    bool answer_found{true};

    for (auto& x: rem)
    {
        auto it = st.end();
        --it;

        if (*it > (x - 1) / 2)
        {
            answer_found = false;
            break;
        }

        st.erase(it);
    }

    if (answer_found)
        cout << rem.size() << endl;
    else
        cout << -1 << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--)
    {
        solve();
    }

    return EXIT_SUCCESS;
}
