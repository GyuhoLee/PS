#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr[20];
int N;
int answer = -1;

void input();
void block(vector<int> arry[], int cnt);
void find_max(vector<int> arry[]);

int main()
{
	input();
	block(arr, 0);
	printf("%d", answer);

	return 0;
}

void input()
{
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int temp;
			scanf_s("%d", &temp);
			arr[i].push_back(temp);
		}
	}
}

void block(vector<int> arry[], int cnt)
{
	if (cnt == 5)
	{
		find_max(arry);
		return;
	}
	vector<int> temp[20];
	
	//LEFT
	for (int i = 0; i < N; i++)
	{
		temp[i] = arry[i];
	}
	for (int i = 0; i < N; i++)
	{
		int store = 0;
		int curPoint = -1;
		for (int j = 0; j < N; j++)
		{
			if (!temp[i][j]) continue;
			curPoint++;
			if (curPoint != j)
			{
				temp[i][curPoint] = temp[i][j];
				temp[i][j] = 0;
			}
			if (!store)
			{
				store = temp[i][curPoint];
				continue;
			}
			if (store == temp[i][curPoint])
			{
				temp[i][curPoint - 1] *= 2;
				temp[i][curPoint] = 0;
				curPoint--;
				store = 0;
			}
			else store = temp[i][curPoint];
		}
	}
	block(temp, cnt + 1);

	//RIGHT
	for (int i = 0; i < N; i++)
	{
		temp[i] = arry[i];
	}
	for (int i = 0; i < N; i++)
	{
		int store = 0;
		int curPoint = N;
		for (int j = N - 1; j >= 0; j--)
		{
			if (!temp[i][j]) continue;
			curPoint--;
			if (curPoint != j)
			{
				temp[i][curPoint] = temp[i][j];
				temp[i][j] = 0;
			}
			if (!store)
			{
				store = temp[i][curPoint];
				continue;
			}
			if (store == temp[i][curPoint])
			{
				temp[i][curPoint + 1] *= 2;
				temp[i][curPoint] = 0;
				curPoint++;
				store = 0;
			}
			else store = temp[i][curPoint];
		}
	}
	block(temp, cnt + 1);

	//UP
	for (int i = 0; i < N; i++)
	{
		temp[i] = arry[i];
	}
	for (int i = 0; i < N; i++)
	{
		int store = 0;
		int curPoint = -1;
		for (int j = 0; j < N; j++)
		{
			if (!temp[j][i]) continue;
			curPoint++;
			if (curPoint != j)
			{
				temp[curPoint][i] = temp[j][i];
				temp[j][i] = 0;
			}
			if (!store)
			{
				store = temp[curPoint][i];
				continue;
			}
			if (store == temp[curPoint][i])
			{
				temp[curPoint - 1][i] *= 2;
				temp[curPoint][i] = 0;
				curPoint--;
				store = 0;
			}
			else store = temp[curPoint][i];
		}
	}
	block(temp, cnt + 1);

	//DOWN
	for (int i = 0; i < N; i++)
	{
		temp[i] = arry[i];
	}
	for (int i = 0; i < N; i++)
	{
		int store = 0;
		int curPoint = N;
		for (int j = N - 1; j >= 0; j--)
		{
			if (!temp[j][i]) continue;
			curPoint--;
			if (curPoint != j)
			{
				temp[curPoint][i] = temp[j][i];
				temp[j][i] = 0;
			}
			if (!store)
			{
				store = temp[curPoint][i];
				continue;
			}
			if (store == temp[curPoint][i])
			{
				temp[curPoint + 1][i] *= 2;
				temp[curPoint][i] = 0;
				curPoint++;
				store = 0;
			}
			else store = temp[curPoint][i];
		}
	}
	block(temp, cnt + 1);

}


void find_max(vector<int> arry[])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			answer = max(answer, arry[i][j]);
		}
	}
}