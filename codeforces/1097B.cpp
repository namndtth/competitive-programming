#include <bits/stdc++.h>

using namespace std;

bool answerFound = false;
vector signs{ -1, +1 };

void backtrack(vector<int>& a, int i, int total)
{
	if (answerFound)
		return;

	if (i == a.size())
	{
		if (total % 360 == 0)
			answerFound = true;
		return;
	}

	for (const auto& sign : signs)
	{
		backtrack(a, i + 1, total + sign * a[i]);
	}
}

int main()
{
	int n;
	cin >> n;

	vector<int> a(n);
	for (auto& x : a)
		cin >> x;

	backtrack(a, 0, 0);

	cout << (answerFound ? "YES" : "NO") << endl;

	return EXIT_SUCCESS;
}
