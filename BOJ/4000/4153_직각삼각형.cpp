#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	while (1)
	{
		int num[3];
		cin >> num[0] >> num[1] >> num[2];
		if (num[0] + num[1] + num[2] == 0) break;
		sort(num, num + 3);
		if (num[0] * num[0] + num[1] * num[1] == num[2] * num[2]) cout << "right" << endl;
		else cout << "wrong" << endl;
	}
	return 0;
}