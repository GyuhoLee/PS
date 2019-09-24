#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<vector<int>>> arr (100);
vector<int> sx = { 1, -1, 0, 0, 0, 0 };
vector<int> sy = { 0, 0, 1, -1, 0, 0 };
vector<int> sz = { 0, 0, 0, 0, 1, -1 };
vector<vector<int>> time(1000000);
int time_count;
int M, N, H;
int tomato();
void change(int i, int j, int k, bool& zero);

int main()
{
	scanf_s("%d %d %d", &M, &N, &H);
	for (int i = 0; i < H; i++)
	{
		vector<vector<int>> temp3(100);
		for (int j = 0; j < N; j++)
		{
			vector<int> temp(100);
			for (int k = 0; k < M; k++)
			{
				int temp2;
				scanf_s("%d", &temp2);
				temp[k]= temp2;
			}
			temp3[j] = temp;
		}
		arr[i] = temp3;
	}
	printf_s("%d", tomato());
	

	return 0;
}

int tomato()
{
	int count = 0;
	bool check = true;
	while (check)
	{
		check = false;
		bool zero = false;
		time_count = 0;
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < N; j++)
			{
				for (int k = 0; k < M; k++)
				{
					if (arr[i][j][k] == 1)
					{
						change(i, j, k, zero);
						arr[i][j][k] = 2;
						check = true;
					}
					else if (arr[i][j][k] == 0) zero = true;
				}
			}
		}
		if (!zero) return count;
		for (int i = 0; i < time_count; i++)
		{
			arr[time[i][0]][time[i][1]][time[i][2]] = 1;
		}
		time_count = 0;
		count++;
	}
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (arr[i][j][k] == 0)
					return -1;
			}
		}
	}
	return count;
}

void change(int i, int j, int k, bool& zero)
{
	for (int l = 0; l < 6; l++)
	{
		if (k + sx[l] >= M || k + sx[l] < 0 || j + sy[l] >= N || j + sy[l] < 0 || i + sz[l] >= H || i + sz[l] < 0) continue;
		if (arr[i + sz[l]][j + sy[l]][k + sx[l]] == 0)
		{
			vector<int> temp(3);
			temp[0] = i + sz[l];
			temp[1] = j + sy[l];
			temp[2] = k + sx[l];
			time[time_count] = temp;
			time_count++;
			zero = true;
		}
	}
}