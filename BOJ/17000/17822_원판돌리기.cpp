#include <iostream>
#include <algorithm>
#include <limits.h>
#include <string.h>
#include <queue>
using namespace std;

int N, M, T;
int arr[51][51];
int x, d, k;
queue<pair<int, int>> q;


void input()
{
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M ; j++)
		{
			cin >> arr[i][j];
		}
	}
}

void turn()
{
	if (d) k = M - k;
	for (int i = x; i <= N; i = i + x)
	{
		for (int j = 0; j < M; j++)
		{
			arr[0][(j + k) % M] = arr[i][j];
		}
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = arr[0][j];
		}
	}
}

void plusMinus()
{
	double total = 0;
	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if(arr[i][j])
			{
				total += arr[i][j];
				cnt++;
			}
		}
	}
	double average = total / cnt;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j])
			{
				if (arr[i][j] > average) arr[i][j]--;
				else if (arr[i][j] < average) arr[i][j]++;
			}
		}
	}	
}


void remove()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] && arr[i][j] == arr[i][(j + 1) % M])
			{
				q.push(make_pair(i, j));
				q.push(make_pair(i, (j + 1) % M));
			}
		}
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] && arr[i][j] == arr[i + 1][j])
			{
				q.push(make_pair(i, j));
				q.push(make_pair(i + 1, j));
			}
		}
	}
	if (q.empty()) plusMinus();
	while (!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();
		arr[temp.first][temp.second] = 0;
	}
}

void calc()
{
	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			answer += arr[i][j];
		}
	}
	cout << answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	while (T--)
	{
		cin >> x >> d >> k;
		turn();
		remove();
	}
	calc();

	return 0;
}