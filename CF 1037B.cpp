#include <iostream>
#include <algorithm>
#include <cmath>
#define lli long long int
using namespace std;

int n, s;
int *arr;
int main()
{
	ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n >> s;
	arr = new int[n];
	int i, j;
	for (i = 0; i < n; i++)
		cin >> arr[i];

	lli res = 0;

	if (n == 1)
	{
		res = abs(s - arr[0]);
	}
	else
	{
		sort(arr, arr + n);
		int median = n / 2;
		res = abs(s - arr[median]);
		i = median - 1;
		j = median + 1;
		while (arr[i] > s && i >= 0)
		{
			res += abs(s - arr[i]);
			i--;
		}
		while (arr[j] < s && j < n)
		{
			res += abs(s - arr[j]);
			j++;
		}
	}
	cout << res;
	return 0;
}