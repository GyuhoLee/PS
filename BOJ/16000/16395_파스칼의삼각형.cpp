#include <iostream>
using namespace std;

int arr[31][31], N, K;

int main()
{
	for (int i = 0; i <= 30; i++) arr[i][0] = 1;
	for (int i = 1; i <= 30; i++)
	{
		for (int j = 1; j <= 30; j++)
		{
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}
	cin >> N >> K;
	cout << arr[N - 1][K - 1];

}