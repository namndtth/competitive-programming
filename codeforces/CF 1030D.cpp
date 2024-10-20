#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
{
    return a ? gcd(b % a, a) : b;
}
int main()
{
    long long n, m, k;
    cin >> n >> m >> k;

    bool isEven = k % 2 == 0;
    long long p = n * m;
    if (isEven)
        k /= 2;
    if (p % k != 0)
    {
        cout << "NO" << endl;
        return 0;
    }
    long long x = gcd(n, k);
    k /= x;
    long long a = n / x;
    x = gcd(m, k);
    k /= x;
    assert (k == 1);
    long long b = m / x;
    if (!isEven)
    {
        if (a < n)
            a += a;
        else
        {
            assert( b < m);
            b += b;
        }
    }
    cout << "YES" << endl;
	cout << "0 0\n";
	cout << 0 << ' ' << b << endl;
	cout << a << ' ' << 0 << endl;

	return 0;
}
