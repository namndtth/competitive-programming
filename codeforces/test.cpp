#include <bits/stdc++.h>

using namespace std;

double square_root(double x)
{
	if (x < 0)
	{
		throw std::out_of_range("x<0");
	}
	return sqrt(x);
}

future<double> f = async(square_root, -1);
double y = f.get();
