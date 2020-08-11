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
#define SIZE 31
#define INF 1111111111
int dy[6] = { -1, 1, 0, 0, 0, 0 };
int dx[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int L, R, C;
char arr[SIZE][SIZE][SIZE];
bool visited[SIZE][SIZE][SIZE];

struct Node
{
	int z, y, x;
	Node(int zz, int yy, int xx) : z(zz), y(yy), x(xx) {}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (1)
	{
		CIN3(L, R, C);
		if (!L) break;
		MS(visited, false);
		queue<pair<int, Node>> q;
		FUP(i, 1, L)
		{
			FUP(j, 1, R)
			{
				FUP(k, 1, C)
				{
					CIN(arr[i][j][k]);
					if (arr[i][j][k] == 'S')
					{
						q.push({ 0, Node(i, j, k) });
						visited[i][j][k] = true;
					}
				}
			}
		}
		bool ok = false;
		while (!q.empty())
		{
			int d = q.front().first;
			Node node = q.front().second;
			int z = node.z;
			int y = node.y;
			int x = node.x;
			q.pop();
			if (arr[z][y][x] == 'E')
			{
				ok = true;
				COUT("Escaped in ");
				COUT(d);
				COUT(" minute(s).\n");
				break;
			}
			FUP(i, 0, 5)
			{
				int nz = z + dz[i];
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (nz < 1 || ny < 1 || nx < 1 || nz > L || ny > R || nx > C || visited[nz][ny][nx] || arr[nz][ny][nx] == '#') continue;
				visited[nz][ny][nx] = true;
				q.push({ d + 1, Node(nz, ny, nx) });
			}
		}
		if (!ok) COUT("Trapped!\n");
	}

	return 0;
}