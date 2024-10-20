#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, A, B;
	cin >> n >> A >> B;

	vector<int> s(n);

	int S = 0;
	for (auto& e : s)
	{
		cin >> e;
		S += e;
	}

	sort(s.begin() + 1, s.end());

	float needed = float(A) / float(B) * s[0];
	int i = n - 1, ans = 0;
	while (i > 0 && S > needed)
	{
		S -= s[i];
		ans++;
		i--;
	}
	cout << ans << endl;

	return EXIT_SUCCESS;
}
