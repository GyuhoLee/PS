#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int N, L;
	scanf("%d %d", &N, &L);
	int arr[100][100][2];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j][0];
			arr[i][j][1] = 0;
		}
	}
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		bool countCheck = true;
		int before = arr[i][0][0];
		for (int j = 1; j < N; j++)
		{
			if (before == arr[i][j][0]) continue;
			else if (abs(arr[i][j][0] - before) > 1)
			{
				countCheck = false;
				break;
			}
			else
			{
				bool lBreak = false;
				if (before > arr[i][j][0])
				{
					if (N - j < L)
					{
						countCheck = false;
						break;
					}
					arr[i][j][1] = 1;
					for (int k = j + 1; k < j + L; k++)
					{
						if (arr[i][j][0] == arr[i][k][0]) arr[i][k][1] = 1;
						else
						{
							countCheck = false;
							lBreak = true;
							break;
						}
					}
				}
				else
				{
					if (j < L)
					{
						countCheck = false;
						break;
					}
					for (int k = j - 1; k >= j - L; k--)
					{
						if (arr[i][k][0] == before && arr[i][k][1] == 0) arr[i][k][1] = 1;
						else
						{
							countCheck = false;
							lBreak = true;
							break;
						}
					}
				}
				if (lBreak == true) break;
			}
			before = arr[i][j][0];
		}
		if (countCheck == true) count++;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			arr[i][j][1] = 0;
		}
	}

	for (int i = 0; i < N; i++)
	{
		bool countCheck = true;
		int before = arr[0][i][0];
		for (int j = 1; j < N; j++)
		{
			if (before == arr[j][i][0]) continue;
			else if (abs(arr[j][i][0] - before) > 1)
			{
				countCheck = false;
				break;
			}
			else
			{
				bool lBreak = false;
				if (before > arr[j][i][0])
				{
					if (N - j < L)
					{
						countCheck = false;
						break;
					}
					arr[j][i][1] = 1;
					for (int k = j + 1; k < j + L; k++)
					{
						if (arr[j][i][0] == arr[k][i][0]) arr[k][i][1] = 1;
						else
						{
							countCheck = false;
							lBreak = true;
							break;
						}
					}
				}
				else
				{
					if (j < L)
					{
						countCheck = false;
						break;
					}
					for (int k = j - 1; k >= j - L; k--)
					{
						if (arr[k][i][0] == before && arr[k][i][1] == 0) arr[k][i][1] = 1;
						else
						{
							countCheck = false;
							lBreak = true;
							break;
						}
					}
				}
				if (lBreak == true) break;
			}
			before = arr[j][i][0];
		}
		if (countCheck == true) count++;
	}
	printf("%d\n", count);

	return 0;
}