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

int N, arr[125][125], d[125][125];
priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int cnt = 1;
	while (1)
	{
		CIN(N);
		if (!N) break;
		FUP(i, 0, N - 1)
		{
			FUP(j, 0, N - 1)
			{
				CIN(arr[i][j]);
				d[i][j] = 111111;
			}
		}
		d[0][0] = arr[0][0];
		pq.push({ arr[0][0], {0, 0} });
		while (!pq.empty())
		{
			int cost = pq.top().first;
			int y = pq.top().second.first;
			int x = pq.top().second.second;
			pq.pop();
			FUP(i, 0, 3)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || nx < 0 || ny >= N || nx >= N || d[ny][nx] <= cost + arr[ny][nx]) continue;
				d[ny][nx] = arr[ny][nx] + cost;
				pq.push({ cost + arr[ny][nx], {ny, nx} });
			}
		}
		COUT2("Problem", cnt++);
		COUT2(":", d[N - 1][N - 1]);
		ENDL;
	}

	return 0;
}