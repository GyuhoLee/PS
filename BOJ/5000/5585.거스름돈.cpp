#include <iostream>
using namespace std;

int main()
{
	int money[6] = { 500, 100, 50, 10, 5, 1 };
	int num, count = 0;
	cin >> num;
	num = 1000 - num;
	for (int i = 0; i < 6; i++)
	{
		count = count + (num / money[i]);
		num %= money[i];
	}
	cout << count;
	
	return 0;
}