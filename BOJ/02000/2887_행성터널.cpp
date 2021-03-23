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

struct Point
{
	int x, y, z, idx;
	Point() {}
	Point(int xx, int yy, int zz, int ii) : x(xx), y(yy), z(zz), idx(ii) {}
};

bool xCmp(Point A, Point B)
{
	return A.x < B.x;
}

bool yCmp(Point A, Point B)
{
	return A.y < B.y;
}

bool zCmp(Point A, Point B)
{
	return A.z < B.z;
}

int getDist(Point A, Point B, int i)
{
	if (i == 0) return abs(A.x - B.x);
	else if (i == 1) return abs(A.y - B.y);
	else return abs(A.z - B.z);
}

int N, pos[3][100000];
bool visited[100000];
Point arr[3][100000];
ll ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	FUP(i, 0, N - 1)
	{
		visited[i] = false;
		CIN3(arr[0][i].x, arr[0][i].y, arr[0][i].z);
		arr[0][i].idx = i;
		arr[1][i] = arr[2][i] = arr[0][i];
	}
	sort(&arr[0][0], &arr[0][0] + N, xCmp);
	sort(&arr[1][0], &arr[1][0] + N, yCmp);
	sort(&arr[2][0], &arr[2][0] + N, zCmp);
	FUP(i, 0, N - 1)
	{
		FUP(j, 0, 2)
		{
			pos[j][arr[j][i].idx] = i;
		}
	}
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, 0 });
	while (!pq.empty())
	{
		int dist = -pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (visited[node]) continue;
		visited[node] = true;
		ans += dist;
		FUP(i, 0, 2)
		{
			int now = pos[i][node];
			if (now != 0)
			{
				int nd = getDist(arr[i][now], arr[i][now - 1], i);
				int ni = arr[i][now - 1].idx;
				pq.push({ -nd, ni });
			}
			if (now != N - 1)
			{
				int nd = getDist(arr[i][now], arr[i][now + 1], i);
				int ni = arr[i][now + 1].idx;
				pq.push({ -nd, ni });
			}
		}
	}
	COUT(ans);

	return 0;
}