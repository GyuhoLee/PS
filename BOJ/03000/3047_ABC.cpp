#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int num[3];
	scanf("%d %d %d", &num[0], &num[1], &num[2]);
	sort(num, num + 3);
	string str;
	cin >> str;
	for (int i = 0; i < 3; i++)
	{
		switch (str[i])
		{
		case 'A': cout << num[0] << ' ';
			break;
		case 'B': cout << num[1] << ' ';
			break;
		case 'C': cout << num[2] << ' ';
			break;
		}
	}

	return 0;
}