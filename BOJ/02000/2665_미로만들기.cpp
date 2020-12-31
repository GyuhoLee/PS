#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define CIN(a) cin >> a
#define CIN2(a, b) cin >> a >> b
#define CIN3(a, b, c) cin >> a >> b >> c
#define COUT(a) cout << a
#define COUT2(a, b) cout << a << ' ' << b
#define COUT3(a, b, c) cout << a << ' ' << b << ' ' << c
#define ENDL cout << '\n'
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N, arr[51][51], d[51][51];

int main()
{
	scanf("%d", &N);
	FUP(i, 1, N)
	{
		FUP(j, 1, N)
		{
			scanf("%1d", &arr[i][j]);
			arr[i][j] ^= 1;
		}
	}
	fill(&d[0][0], &d[50][51], INT_MAX);
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ -arr[1][1], {1, 1} });
	d[1][1] = arr[1][1];
	while (!pq.empty())
	{
		int dist = -pq.top().first;
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		pq.pop();
		if (dist > d[y][x]) continue;
		FUP(i, 0, 3)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > N || d[ny][nx] <= dist + arr[ny][nx]) continue;
			d[ny][nx] = dist + arr[ny][nx];
			pq.push({ -d[ny][nx], {ny, nx} });
		}
	}
	COUT(d[N][N]);

	return 0;
}