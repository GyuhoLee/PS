#include <iostream>
#include <vector>
using namespace std;

int N;
bool visited[100001];
int parent[100001];
vector<int> tree[100001];



void findParent(int nodeNum)

{
	visited[nodeNum] = true;
	//DFS
	for (int i = 0; i < tree[nodeNum].size(); i++)
	{
		int next = tree[nodeNum][i];
		if (!visited[next])
		{
			parent[next] = nodeNum;
			findParent(next);
		}
	}
}

int main()

{
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++)
	{
		int node1, node2;
		scanf("%d %d", &node1, &node2);
		tree[node1].push_back(node2);
		tree[node2].push_back(node1);
	}
	findParent(1);
	for (int i = 2; i <= N; i++)
	{
		printf("%d\n", parent[i]);
	}

	return 0;

}