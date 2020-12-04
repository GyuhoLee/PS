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

int ans = 0;
char arr[12][6];

void down()
{
	FUP(j, 0, 5)
	{
		int idx = 11;
		FDOWN(i, 11, 0)
		{
			if (arr[i][j] == '.') continue;
			if (i == idx) idx--;
			else
			{
				arr[idx--][j] = arr[i][j];
				arr[i][j] = '.';
			}

		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	FUP(i, 0, 11)
	{
		FUP(j, 0, 5)
		{
			CIN(arr[i][j]);
		}
	}

	while (true)
	{
		bool ok = false;

		FUP(i, 0, 11)
		{
			FUP(j, 0, 5)
			{
				if (arr[i][j] == '.') continue;
				queue<pair<int, int>> q;
				set<pair<int, int>> s;
				q.push({ i, j });
				s.insert({ i, j });
				while (!q.empty())
				{
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					FUP(k, 0, 3)
					{
						int ny = y + dy[k];
						int nx = x + dx[k];
						if (ny > 11 || nx > 5 || ny < 0 || nx < 0 || arr[ny][nx] != arr[y][x]) continue;
						if (s.count({ ny, nx })) continue;
						q.push({ ny, nx });
						s.insert({ ny, nx });
					}
				}
				if (s.size() >= 4)
				{
					ok = true;
					for (auto p : s)
					{
						arr[p.first][p.second] = '.';
					}
				}
			}
		}

		if (!ok) break;
		ans++;
		down();
	}

	COUT(ans);

	return 0;
}