#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	int num[11];
	num[1] = 1;
	num[2] = 2;
	num[3] = 4;
	for (int i = 4; i < 11; i++)
	{
		num[i] = num[i - 3] + num[i - 2] + num[i - 1];
	}
	while (T--)
	{
		int n;
		cin >> n;
		cout << num[n] << '\n';
	}
	return 0;
}