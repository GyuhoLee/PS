#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

int N, M, K;
int S, D;
int arr[1001][1001]; // i에서 j까지의 직접적인 거리(1번만에)를 담아둠. 기본은 0이다
int d[1001][1001]; // S에서 i까지 길을 j번 거쳐서 거리. 
int minD[1001]; // 이건 S에서 i까지 최솟값. 왜냐면 d[i][j]가 j가 낮은수부터 저장하기 때문에, 더 많은 길을 통과했으면 이전 도착한 값보다는 작아야 쓸모있다.
vector<int> connect[1001]; // 각 노드에서 갈 수 있는 노드를 저장해놓음.
int totalK = 0; //k를 계속 더해줌. w값을 수정하는것보다 이게 낫다.

void input()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			arr[i][j] = 0;
			d[i][j] = 0;
		}
	}
	scanf_s("%d %d %d", &N, &M, &K);
	scanf_s("%d %d", &S, &D);
	for (int i = 0; i < M; i++)
	{
		int a, b, w;
		scanf_s("%d %d %d", &a, &b, &w);
		arr[a][b] = w;	//양 방향 거리 설정
		arr[b][a] = w;
		connect[a].push_back(b);	//양 방향 노드 저장
		connect[b].push_back(a);
	}
}

void find_road()
{
	for (int i = 1; i <= N; i++)
	{
		minD[i] = INT_MAX;	//기본값은 최댓값
	}
	minD[S] = 0;	//첫 시작점은 0이다.
	for (auto iter = connect[S].begin(); iter != connect[S].end(); iter++)
	{
		d[*iter][1] = arr[S][*iter];	//길을 1개만 쓴 노드는 저장해놓음.
	}
	for (int j = 1; j < N; j++)	//j가 밖에 있어야 된다. 그리고 N - 1개 거쳤을 때까지만 하면 됨.
	{
		for (int i = 1; i <= N; i++) //모든 노드 확인
		{
			if (d[i][j]) // 값이 저장되어 있는 경우에만.
			{
				for (auto iter = connect[i].begin(); iter != connect[i].end(); iter++)	// i에서 갈 수 있는 노드들 확인.
				{
					if (minD[*iter] > d[i][j] + arr[i][*iter])	// 저장해놓은 값보다 더 작을때만
					{
						d[*iter][j + 1] = d[i][j] + arr[i][*iter];	//j에서 1개 더 많은 길을 써서, iterator가 가르키는 노드까지의 값 설정
						minD[*iter] = d[*iter][j + 1];	//최솟값 수정
					}
				}
			}
		}
	}

	// 아래는 초기 최소거리 측정. N까지 도는 이유는 갈 수 있는 길의 최댓값은 도시의 갯수를 넘을 수 없기 때문.
	int answer = INT_MAX;
	for (int i = 1; i <= N; i++)
	{
		if (d[D][i])
		{
			answer = min(answer, d[D][i]);
		}
	}
	printf("%d\n", answer);

}

void printK()
{
	int num;
	scanf_s("%d", &num);
	totalK += num;	//totalK 값은 축적된다.
	//아래 출력 구문은 초기와 동일.
	int answer = INT_MAX;
	for (int i = 1; i <= N; i++)
	{
		if (d[D][i])
		{
			answer = min(answer, d[D][i] + totalK * i);	//j의 값이 길의 갯수이기 때문에, 더해진 세금을 곱해주면 된다.
		}
	}
	printf("%d\n", answer);
}

int main()
{
	input();
	find_road();
	while (K--)
	{
		printK();
	}

	return 0;
}