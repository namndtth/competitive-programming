#include <iostream>
using namespace std;
int main()
{
    int m, n, a, b;
    cin >> n >> m >> a >> b;
    if (n < m)
        cout << min(n * a, b);
    else
        cout << min(min(n * a, (n - n / m * m) * a + n / m * b), (n / m + 1) * b);
    return 0;
}