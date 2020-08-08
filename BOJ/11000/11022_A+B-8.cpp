#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int num1, num2;
		cin >> num1 >> num2;
		cout << "Case #" << i << ": " << num1 << " + " << num2 << " = " << num1 + num2 << endl;
	}

	return 0;
}