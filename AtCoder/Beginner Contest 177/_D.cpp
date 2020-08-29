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

int N, M, a, b, ans = 0, cnt;
vector<int> arr[200001];
bool visited[200001];

void DFS(int node)
{
	cnt++;
	visited[node] = true;
	for (int next : arr[node])
	{
		if (!visited[next])
		{
			DFS(next);
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	CIN2(N, M);
	while (M--)
	{
		CIN2(a, b);
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	MS(visited, false);
	FUP(i, 1, N)
	{
		cnt = 0;
		if (!visited[i])
		{
			DFS(i);
		}
		ans = max(cnt, ans);
	}
	COUT(ans);

	return 0;
}