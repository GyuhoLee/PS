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

int N, M, a, b, num[10001], ans = 0;
bool visited[10001];
vector<int> arr[10001];

void DFS(int idx, int node)
{
	visited[node] = true;
	ans = max(ans, ++num[idx]);
	for (int next : arr[node])
	{
		if (!visited[next]) DFS(idx, next);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(num, 0);
	CIN2(N, M);
	while (M--)
	{
		CIN2(a, b);
		arr[b].push_back(a);
	}
	FUP(i, 1, N)
	{
		MS(visited, false);
		DFS(i, i);
	}
	FUP(i, 1, N)
	{
		if (num[i] == ans)
		{
			COUT2(i, "");
		}
	}



	return 0;
}