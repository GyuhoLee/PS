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

int T, N;
pair<int, int> arr[102];
bool visited[102];

void DFS(int node)
{
	visited[node] = true;
	FUP(i, 1, N)
	{
		if (visited[i] || abs(arr[node].first - arr[i].first) + abs(arr[node].second - arr[i].second) > 1000) continue;
		DFS(i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(T);
	while (T--)
	{
		MS(visited, false);
		CIN(N);
		N++;
		FUP(i, 0, N)
		{
			CIN2(arr[i].first, arr[i].second);
		}
		DFS(0);
		visited[N] ? COUT("happy\n") : COUT("sad\n");
	}

	return 0;
}