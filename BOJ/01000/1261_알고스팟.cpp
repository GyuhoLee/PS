#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define CIN(a) cin >> a;
#define CIN2(a, b) cin >> a >> b
#define CIN3(a, b, c) cin >> a >> b >> c
#define COUT(a) cout << a
#define COUT2(a, b) cout << a << ' ' << b
#define COUT3(a, b, c) cout << a << ' ' << b << ' ' << c
#define ENDL cout << '\n'
#define SIZE 101
#define INF 111111
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N, M;
char arr[SIZE][SIZE];
int D[SIZE][SIZE];

void dijkstra()
{
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	pq.push({ 0, {1, 1 } });
	D[1][1] = 0;
	while (!pq.empty())
	{
		int distance = pq.top().first;
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		pq.pop();
		if (distance > D[y][x]) continue;
		D[y][x] = distance;
		if (y == N && x == M) break;
		FUP(i, 0, 3)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > M) continue;
			int num = arr[ny][nx] - '0';
			if (D[ny][nx] > D[y][x] + num)
			{
				D[ny][nx] = D[y][x] + num;
				pq.push({ D[ny][nx], {ny, nx} });
			}
		}
	}
	COUT(D[N][M]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(M, N);
	FUP(i, 1, N)
	{
		FUP(j, 1, M)
		{
			CIN(arr[i][j]);
			D[i][j] = INF;
		}
	}
	dijkstra();
}