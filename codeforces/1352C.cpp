#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        if (n > k)
            cout << k;
        else
        {
            long long ans;
            long long nguyen = k / (n - 1);
            long long du = k - (n - 1) * nguyen;
            ans = (du == 0 ? n * nguyen - 1 : n * nguyen + du);
            cout << ans;
        }
        cout << endl;
    }
    return 0;
}