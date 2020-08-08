#include <bits/stdc++.h>
using namespace std;

int N, K;
int go[1000];
queue<pair<int, int>> q;
bool visited[100001];
int answer = INT_MAX;
int answerCnt = 0;

void BFS()
{
	memset(visited, false, sizeof(visited));
	q.push({ N, 0 });
	visited[N] = true;
	while (!q.empty() && answer >= q.front().second)
	{
		int num = q.front().first;
		int cnt = q.front().second;
		q.pop();
		visited[num] = true;

		if (num == K)
		{
			answerCnt++;
			answer = cnt;
			continue;
		}

		if (num * 2 < 100001 && !visited[num * 2]) q.push({ num * 2, cnt + 1 });
		if (num + 1 < 100001 && !visited[num + 1]) q.push({ num + 1, cnt + 1 });
		if (num - 1 >= 0 && !visited[num - 1]) q.push({ num - 1, cnt + 1 });
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	go[0] = 0;
	//for (int i = 1; i < N; i++) go[i] = go[i - 1] + i;
	BFS();
	printf("%d %d", answer, answerCnt);

	return 0;
}