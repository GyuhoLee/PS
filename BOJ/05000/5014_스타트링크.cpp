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

int F, S, G, U, D;
bool visited[1000001];
queue<pair<int, int>> q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(visited, false);
	CIN3(F, S, G);
	CIN2(U, D);

	visited[S] = true;
	q.push({ S, 0 });
	while (!q.empty())
	{
		int num = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (num == G)
		{
			COUT(cnt);
			break;
		}
		if (num + U <= F && !visited[num + U])
		{
			visited[num + U] = true;
			q.push({ num + U, cnt + 1 });
		}
		if (num - D > 0 && !visited[num - D])
		{
			visited[num - D] = true;
			q.push({ num - D , cnt + 1 });
		}
	}
	if (!visited[G]) COUT("use the stairs");


	return 0;
}