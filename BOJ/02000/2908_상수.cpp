#include <iostream>
using namespace std;

int main()
{
	char num1[4], num2[4];
	cin >> num1 >> num2;
	bool isLeftBig;
	if (num1[2] > num2[2]) isLeftBig = true;
	else if (num1[2] < num2[2]) isLeftBig = false;
	else
	{
		if (num1[1] > num2[1]) isLeftBig = true;
		else if (num1[1] < num2[1]) isLeftBig = false;
		else
		{
			if (num1[0] > num2[0]) isLeftBig = true;
			else if (num1[0] < num2[0]) isLeftBig = false;
		}
	}
	if (isLeftBig == true)
		cout << num1[2] << num1[1] << num1[0];
	else
		cout << num2[2] << num2[1] << num2[0];

	return 0;
}