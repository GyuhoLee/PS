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
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
#define INF 987654321

int H, W, d[1001][1001];
char arr[1001][1001];
pair<int, int> C, D;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(H, W);
	CIN2(C.first, C.second);
	CIN2(D.first, D.second);
	FUP(i, 1, H)
	{
		FUP(j, 1, W)
		{
			CIN(arr[i][j]);
			d[i][j] = INF;
		}
	}
	d[C.first][C.second] = 0;
	priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	pq.push({ 0, {C.first, C.second} });
	while (!pq.empty())
	{
		int dis = pq.top().first;
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		pq.pop();
		if (y == D.first && x == D.second) break;
		FUP(i, 0, 3)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny <= 0 || nx <= 0 || ny > H || nx > W || arr[ny][nx] == '#') continue;
			if (d[ny][nx] <= dis) continue;
			d[ny][nx] = dis;
			pq.push({ dis, {ny, nx} });
		}
		FUP(i, -2, 2)
		{
			FUP(j, -2, 2)
			{
				int ny = y + i;
				int nx = x + j;
				if (ny <= 0 || nx <= 0 || ny > H || nx > W || arr[ny][nx] == '#') continue;
				if (d[ny][nx] <= dis + 1) continue;
				d[ny][nx] = dis + 1;
				pq.push({ dis + 1, {ny, nx} });
			}
		}
	}
	d[D.first][D.second] == INF ? COUT(-1) : COUT(d[D.first][D.second]);


	return 0;
}