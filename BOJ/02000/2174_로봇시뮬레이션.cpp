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
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

struct Robot
{
	int y, x, d;
	Robot() {}
	Robot(int yy, int xx, int dd) : y(yy), x(xx), d(dd) {}
};

int A, B, N, M, arr[101][101], idx, repeat;
Robot robot[101];
map<char, int> direct = { {'E', 0}, {'N', 1}, {'W', 2}, {'S', 3} };
char command;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(arr, 0);
	CIN2(B, A);
	CIN2(N, M);
	FUP(i, 1, N)
	{
		int y, x;
		char d;
		CIN3(x, y, d);
		robot[i] = Robot(y, x, direct[d]);
		arr[y][x] = i;
	}
	while (M--)
	{
		CIN3(idx, command, repeat);
		if (command == 'F')
		{
			int ny = robot[idx].y;
			int nx = robot[idx].x;
			int d = robot[idx].d;
			arr[ny][nx] = 0;
			FUP(i, 1, repeat)
			{
				ny += dy[d];
				nx += dx[d];
				if (ny < 1 || nx < 1 || ny > A || nx > B)
				{
					COUT("Robot " + to_string(idx) + " crashes into the wall");
					return 0;
				}
				if (arr[ny][nx])
				{
					COUT("Robot " + to_string(idx) + " crashes into robot " + to_string(arr[ny][nx]));
					return 0;
				}
			}
			arr[ny][nx] = idx;
			robot[idx] = Robot(ny, nx, d);
		}
		else
		{
			repeat %= 4;
			command == 'R' ? repeat = 4 - repeat :repeat;
			robot[idx].d = (robot[idx].d + repeat) % 4;
		}
	}
	COUT("OK");


	return 0;
}