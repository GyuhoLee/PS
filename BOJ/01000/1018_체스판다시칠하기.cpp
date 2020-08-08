#include <iostream>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	char pan[51][51];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin.ignore(0, '\n');
			cin >> pan[i][j];
		}
	}
	int min = 64;
	for (int i = 0; i <= N - 8; i++)
	{
		for (int l = 0; l <= M - 8; l++)
		{
			int temp = 0;
			for (int j = 0; j < 8; j++)
			{
				for (int k = 0; k < 8; k++)
				{
					switch ((j + k) % 2)
					{
					case 0:
						if (pan[i + j][l + k] == 'W') temp++;
						break;
					case 1:
						if (pan[i + j][l + k] == 'B') temp++;
					}
				}
			}
			if (temp > 32) temp = 64 - temp;
			if (temp < min) min = temp;
		}
	}
	cout << min;

	return 0;
}