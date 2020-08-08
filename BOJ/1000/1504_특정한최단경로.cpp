#include <iostream>
#include <algorithm>
#include <string.h>
#include <limits.h>
#include <vector>
using namespace std;

int N, E;
int a, b, c;
int M, L;
int arr[801][801];
int d[3][801];	//3개씩 둔 이유는 시작점, 중간노드1 , 중간노드2 3개에서의 다익스트라를 구현하는데 편하려고
bool visited[3][801];
int num[3];
vector<int> connect[801];
int answer = INT_MAX;

void input()
{
	memset(arr, 0, sizeof(arr));
	scanf_s("%d %d", &N, &E);
	while (E--)
	{
		scanf_s("%d %d %d", &a, &b, &c);
		arr[a][b] = arr[b][a] = c;
		connect[a].push_back(b);
		connect[b].push_back(a);
	}
	scanf_s("%d %d", &M, &L);
	num[0] = 1;
	num[1] = M;
	num[2] = L;
}

void find_d()
{
	for (int l = 0; l < 3; l++)
	{
		for (int i = 1; i <= N; i++)
		{
			visited[l][i] = false;
			d[l][i] = INT_MAX;
		}
		d[l][num[l]] = 0;
		while (true)
		{
			int cost = INT_MAX;
			int node = 0;
			for (int i = 1; i <= N; i++)
			{
				if (!visited[l][i] && cost > d[l][i])
				{
					cost = d[l][i];
					node = i;
				}
			}

			if (!node)
			{
				break;
			}
			visited[l][node] = true;
			for (auto iter = connect[node].begin(); iter != connect[node].end(); iter++)
			{
				if (d[l][*iter] > d[l][node] + arr[node][*iter])
				{
					d[l] [*iter] = d[l][node] + arr[node][*iter];
				}
			}
		}

	}
}

//각 노드에서 거리가 있는 경우에만 구현해주면 된다.
void solve()
{
	int answer1 = INT_MAX, answer2 = INT_MAX;
	if (d[0][M] != INT_MAX && d[1][L] != INT_MAX && d[2][N] != INT_MAX)
	{
		answer1 = d[0][M] + d[1][L] + d[2][N];
	}
	if (d[0][L] != INT_MAX && d[2][M] != INT_MAX && d[1][N] != INT_MAX)
	{
		answer2 = d[0][L] + d[2][M] + d[1][N];
	}
	answer = min(answer1, answer2);
	if (answer == INT_MAX)
	{
		answer = -1;
	}
}

int main()
{
	input();
	find_d();
	solve();
	printf("%d", answer);

	return 0;
}