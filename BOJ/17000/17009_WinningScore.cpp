#include <bits/stdc++.h>
using namespace std;

int main()
{
	int arr[2][4];
	for (int i = 0; i < 2; i++)
	{
		arr[i][0] = 0;
		for (int j = 3; j > 0; j--)
		{
			cin >> arr[i][j];
			arr[i][0] += (arr[i][j] * j);
		}
	}
	if (arr[0][0] > arr[1][0]) cout << "A";
	else if (arr[0][0] < arr[1][0]) cout << "B";
	else cout << "T";

	return 0;
}