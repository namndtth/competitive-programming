#include <bits/stdc++.h>
using namespace std;

class Foo
{
public:
	Foo()
	{
		m_x = 5;
	}
	void print()
	{
		cout << m_x << endl;
	}
private:
	int m_x;
};

void print()
{
	cout << "hallo";
}
int main()
{
	void (*funcPtr)();
	funcPtr = &print;
	funcPtr();

	return EXIT_SUCCESS;
}
