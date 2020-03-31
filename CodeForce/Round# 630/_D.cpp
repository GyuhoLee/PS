#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int arr[3][3];
	int K;
	cin >> K;
	if (K == 0)
	{
		cout << "1 1\n300000";
		return 0;
	}
	cout << "3 3\n";
	int num = 1;
	while (K >= num) { num *= 2; };
	arr[0][0] = arr[2][1] = num + K;
	arr[1][0] = arr[2][0] = num;
	arr[0][1] = arr[1][1] = arr[2][2] = K;
	arr[0][2] = arr[1][2] = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << arr[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}