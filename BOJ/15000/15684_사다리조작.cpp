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

int N, M, H, ans = INF, arr[31][12], a, b;


bool ok()
{
	FUP(i, 1, N)
	{
		int arrive = i;
		FUP(j, 1, H)
		{
			if (arr[j][arrive]) arrive++;
			else if (arr[j][arrive - 1]) arrive--;
		}
		if (arrive != i) return false;
	}
	return true;
}

void DFS(int now, int cnt)
{
	if (cnt > 3) return;
	if (ok())
	{
		ans = min(ans, cnt);
		return;
	}
	FUP(i, now, H)
	{
		FUP(j, 1, N)
		{
			if (arr[i][j] || arr[i][j - 1] || arr[i][j + 1]) continue;
			arr[i][j] = 1;
			DFS(i, cnt + 1);
			arr[i][j] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(arr, 0);
	CIN3(N, M, H);
	while(M--)
	{
		CIN2(a, b);
		arr[a][b] = 1;
	}
	DFS(1, 0);

	ans == INF ? COUT(-1) : COUT(ans);

	return 0;
}