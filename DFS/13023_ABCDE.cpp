#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> arr(2000);
int answer = 0;
vector<bool> go(2000, false);
void find();
void move(int n, int count);

int main()
{
	scanf_s("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int temp1, temp2;
		scanf_s("%d %d", &temp1, &temp2);
		arr[temp1].push_back(temp2);
		arr[temp2].push_back(temp1);
	}
	find();
	printf_s("%d", answer);

	return 0;
}

void find()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			if (go[arr[i][j]] == true) continue;
			go[i] = true;
			move(arr[i][j], 2);
			go[i] = false;
		}
	}
}

void move(int n, int count)
{
	go[n] = true;
	if (count == 5)
	{
		answer = 1;
		return;
	}
	for (int i = 0; i < arr[n].size(); i++)
	{
		if (go[arr[n][i]] == true) continue;
		move(arr[n][i], count + 1);
	}
	go[n] = false;
}