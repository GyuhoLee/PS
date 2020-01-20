#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <string.h>
#include <queue>
using namespace std;

int N, M, S, D;
int U, V, P;
int arr[500][500] = { 0, };	//i에서 j까지의 거리
int d[500];	//S에서 i까지의 최솟값
bool visited[500];	//i번째 노드를 최솟값으로 정하였는가.
vector<int> connect[500];	//i번째에서 각 갈수있는 노드들 저장
vector<int> road[500];	//S에서 i까지의 최소 경로 (ex. 1- 2- 3- 4)
vector<vector<int>> overlab[500];	//최솟값이 겹칠경우 저장해놓기
int answer;

bool input()
{
	scanf_s("%d %d", &N, &M);
	if (!(N + M)) return false;	// 둘다 0이면 탈출
	scanf_s("%d %d", &S, &D);
	/*	이거쓰니 메모리초과 났음. capacity때문인가
	connect->clear();
	road->clear();
	overlab->clear();	
	*/
	for (int i = 0; i < 500; i++)
	{
		connect[i].clear();
		road[i].clear();
		overlab[i].clear();
	}
	while (M--)
	{
		scanf_s("%d %d %d", &U, &V, &P);
		arr[U][V] = P;
		connect[U].push_back(V);
	}
	return true;
}

void find_min()
{
	memset(visited, false, sizeof(visited));
	vector<int> v;	//road를 위한 벡터
	answer = INT_MAX;
	for (int i = 0; i < N; i++)
	{
		d[i] = INT_MAX;	//모든 곳의 거리를 최댓값으로
	}
	d[S] = 0;	//출발점은 당연히 0
	v.push_back(S);
	road[S] = v;	//S까지는 S가 경로의 끝. 이걸 계속 늘려나가며 road를 만들겠다
	while (true)	//다익스트라 알고리즘과 유사하다
	{
		int cost = INT_MAX;	//최솟값 저장할 변수
		int node = -1;	//최솟값의 노드
		for (int i = 0; i < N; i++)
		{
			if (!visited[i] && (cost > d[i]))	//visited는 이미 끝난 노드. 나머지 노드들 중에서 최솟값
			{
				cost = d[i];
				node = i;
			}
		}
		if (cost == INT_MAX)	//노드를 구하지 못하였으면, 탈출(D에 도착할시 while문이 끝나기 때문에)
		{
			answer = -1;
			return;
		}
		if (node == D)	//목적지에 도달했으면 굳이 더 구할 필요 없다.
		{
			break;
		}
		visited[node] = true;	//선택된 노드는 최솟값이 결정되었다.
		for (auto iter = connect[node].begin(); iter != connect[node].end(); iter++)	//해당 노드들로부터 갈 수 있는 노드들 값 재입력하기
		{
			if (d[*iter] > d[node] + arr[node][*iter])	//기존 경로보다 더 짧게 갈 수 있는 경우,
			{
				d[*iter] = d[node] + arr[node][*iter];	//해당 길이 수정
				road[*iter] = road[node];	//해당 노드까지의 경로를 수정해준다.
				road[*iter].push_back(*iter);	//지금까지의 노드 + 이동할 노드
				overlab[*iter].clear();	//기존 겹치는 벡터들보다 거리가 짧기 때문에 clear해준다.
				if (overlab[node].size())	//지금까지의 노드의 최솟값이 같을때 (ex. 1 - 3 - 2, 1 - 2  의 값이 같을때는 overlab값이 있다.)
				{
					for (auto iter2 = overlab[node].begin(); iter2 != overlab[node].end(); iter2++)	//경로의 갯수만큼.
					{
						vector<int> temp = *iter2;	//벡터를 받아옴
						temp.push_back(*iter);
						overlab[*iter].push_back(temp);	//overlab에 위 겹치는 경로까지 넣어놓음.
					}
				}
			}
			else if (d[*iter] == d[node] + arr[node][*iter])	//최솟값이 똑같을때에도, 해당 경로를 삭제해줘야 한다.
			{
				vector<int> temp = road[node];
				temp.push_back(*iter);
				overlab[*iter].push_back(temp);	//다음 노드의 overlab에 현재까지의 경로를 추가한다.
				if (overlab[node].size())	//이번 노드의 overlab 값이 있는 경우, 이 또한 추가해주어야된다.
				{
					for (auto iter2 = overlab[node].begin(); iter2 != overlab[node].end(); iter2++)
					{
						vector<int> temp2 = *iter2;
						temp2.push_back(*iter);
						overlab[*iter].push_back(temp2);
					}
				}
			}
		}
	}
	int temp = 0;
	for (int i = 0; i < road[D].size() - 1; i++)	//road가 1 - 2 - 3 - 4 의 형태로 있으므로, i번째에서 i + 1번째로 가는 거리의 합이다.
	{
		temp += arr[road[D][i]][road[D][i + 1]];
	}
	answer = temp;

}

void remove_min()
{
	//road에 저장되어있는 경로들을 삭제한다.
	for (int i = 0; i < road[D].size() - 1; i++)
	{
		arr[road[D][i]][road[D][i + 1]] = 0;
		for (auto iter = connect[road[D][i]].begin(); iter != connect[road[D][i]].end(); iter++)
		{
			if (*iter == road[D][i + 1])
			{
				connect[road[D][i]].erase(iter);
				break;
			}
		}
	}

	//마찬가지로 overlab에 저장되어있는 경로들을 삭제한다.
	vector<int> temp;
	while (!overlab[D].empty())
	{
		temp = overlab[D].back();
		overlab[D].pop_back();
		for (int i = 0; i < temp.size() - 1; i++)
		{
			arr[temp[i]][temp[i + 1]] = 0;
			for (auto iter = connect[temp[i]].begin(); iter != connect[temp[i]].end(); iter++)
			{
				if (*iter == temp[i + 1])
				{
					connect[temp[i]].erase(iter);
					break;
				}
			}
		}
	}
}

int main()
{
	while(input())
	{
		find_min();
		int temp = answer;
		if (answer != -1)	//애초에 경로가 없는 경우는 생각할 필요 없다.
		{
			while (temp == answer)
			{
				remove_min();
				find_min();
			}
		}
		if (answer == INT_MAX) printf("-1\n");
		else printf("%d\n", answer);
	}


	return 0;
}