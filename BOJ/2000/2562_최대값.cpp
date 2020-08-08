#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
    N = 9;
	int a = -1;
	int b = 1;
	int num;
	for(int i = 1; i <= N; i++)
	{
		cin >> num;
		if (a < num)
		{
			a = num;
			b = i;
		}
	}
	cout << a << endl << b;

	return 0;
}
