#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define ENDL '\n'
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	bool arr[100][100];
	MS(arr, false);
	int answer = 0;
	int N, M;
	cin >> M >> N;
	int direct = 0;
	int y = 0, x = 0;
	arr[0][0] = true;
	while (1)
	{
		int ny = y + dy[direct];
		int nx = x + dx[direct];
		if (ny >= M || nx >= N || ny < 0 || nx < 0 || arr[ny][nx])
		{
			direct++;
			direct %= 4;
			ny = y + dy[direct];
			nx = x + dx[direct];
			if (arr[ny][nx]) break;
			answer++;
		}
		y = ny;
		x = nx;
		arr[ny][nx] = true;
	}
	cout << answer;

	return 0;
}