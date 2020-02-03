#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int T;
int num[45];
int ureka[1001];

void setting()
{
	memset(ureka, 0, sizeof(ureka));
	num[0] = 0;
	for (int i = 1; i < 45; i++)
	{
		num[i] = num[i - 1] + i;
	}
	for (int i = 1; i < 45; i++)
	{
		for (int j = 1; j < 45; j++)
		{
			for (int k = 1; k < 45; k++)
			{
				if (num[i] + num[j] + num[k] <= 1000)
				{
					ureka[num[i] + num[j] + num[k]] = 1;
				}
			}
		}
	}
}
int main()
{
	setting();
	cin >> T;
	while (T--)
	{
		int num;
		cin >> num;
		cout << ureka[num] << '\n';
	}

	return 0;
}