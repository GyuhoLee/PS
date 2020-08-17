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

int T, V, E, u, v, num[20001];
vector<int> arr[20001];
string answer;

void DFS(int node, int color)
{
	num[node] = color;
	for (int next : arr[node])
	{
		if (num[next] == -1) DFS(next, (color + 1) % 2);
		else if (num[next] == num[node]) answer = "NO";
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
		answer = "YES";
		CIN2(V, E);
		FUP(i, 1, V)
		{
			arr[i].clear();
			num[i] = -1;
		}
		while (E--)
		{
			CIN2(u, v);
			arr[u].push_back(v);
			arr[v].push_back(u);
		}
		FUP(i, 1, V)
		{
			if (num[i] == -1) DFS(i, 1);
		}
		COUT(answer);
		ENDL;
	}

	return 0;
}