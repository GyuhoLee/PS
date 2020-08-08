#include <iostream>

#define MAX_HEIGHT 3072 // 3*2^10;
#define MAX_WIDTH  6143 // 2*MAX_HEIGHT - 1

using namespace std;

int arr[MAX_HEIGHT][MAX_WIDTH];

void printStars(int row, int col, int n)
{
	// x, y : vertex position, n : height
	if (n == 3)
	{
		arr[row][col] = 1;
		arr[row + 1][col - 1] = 1;
		arr[row + 1][col + 1] = 1;
		arr[row + 2][col - 2] = 1;
		arr[row + 2][col - 1] = 1;
		arr[row + 2][col] = 1;
		arr[row + 2][col + 1] = 1;
		arr[row + 2][col + 2] = 1;
		return;
	}
	printStars(row, col, n / 2);
	printStars(row + n / 2, col - n / 2, n / 2);
	printStars(row + n / 2, col + n / 2, n / 2);
}

int main(void)
{
	int N;
	cin >> N;

	printStars(0, MAX_WIDTH/2, N);
	for (int i = 0; i < N; i++)
	{
		for (int j = MAX_WIDTH/2 - N+1; j <= MAX_WIDTH/2+ N-1; j++)
		{
			if (arr[i][j] == 1)
				cout << '*';
			else
				cout << ' ';
		}
		cout << endl;
	}

	return 0;
}
