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

int T, N, arr[1001];
bool visited[1001];

void DFS(int num)
{
	if (!visited[arr[num]])
	{
		visited[arr[num]] = true;
		DFS(arr[num]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	CIN(T);
	while (T--)
	{
		int N, answer = 0;;
		CIN(N);
		FUP(i, 1, N) CIN(arr[i]);
		MS(visited, false);
		FUP(i, 1, N)
		{
			if (!visited[i])
			{
				visited[i] = true;
				answer++;
				DFS(i);
			}
		}
		COUT(answer);
		ENDL;
	}

	return 0;
}