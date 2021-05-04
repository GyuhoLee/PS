#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
#define SIZE 1111111

int arr[SIZE + 1], N;

int main()
{
	for (int i = 2; i <= SIZE; i++) arr[i] = i;
	for (int i = 2; i <= sqrt(SIZE); i++)
	{
		if (arr[i] == 0) continue;
		for (int j = i + i; j <= SIZE; j += i) arr[j] = 0;
	}

	cin >> N;

	for (int i = N; i <= SIZE; i++)
	{
		if (arr[i] != 0)
		{
			bool ok = true;
			string tmp = to_string(i);
			for (int j = 0; j <= (int)tmp.length() / 2 - 1; j++)
			{
				if (tmp[j] != tmp[tmp.length() - 1 - j])
				{
					ok = false;
					break;
				}
			}
			if (ok)
			{
				cout << i;
				break;
			}
		}
	}
		 
	return 0;
}