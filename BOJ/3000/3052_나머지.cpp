#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
	set<int> s;
	int i = 10;
	while (i--)
	{
		int num;
		cin >> num;
		s.insert(num % 42);
	}
	cout << s.size();

	return 0;
}
