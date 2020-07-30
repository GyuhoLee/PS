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

int N, M;
int p[100000], h[100000], num[100000];
bool visited[100000], answer;
vector<int> load[100000];

int DFS_person(int node)
{
	visited[node] = true;
	for (int i : load[node])
	{
		if (visited[i]) continue;
		num[node] += DFS_person(i);
	}
	return num[node];
}

int DFS_check(int node)
{
	if (!answer) return 0;
	if (num[node] % 2 != abs(h[node]) % 2)
	{
		answer = false;
		return 0;
	}
	if (abs(h[node]) > num[node])
	{
		answer = false;
		return 0;
	}
	visited[node] = false;
	int happy = 0;
	for (int i : load[node])
	{
		if (!visited[i]) continue;
		happy += DFS_check(i);
		
	}
	int now = num[node] - p[node];
	int mod = num[node] - happy;
	if (happy - mod > h[node])
	{
		answer = false;
		return 0;
	}
	if (h[node] > 0) return (num[node] + 1) / 2 + h[node] / 2;
	else return num[node] / 2 + h[node] / 2;
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
		answer = true;
		CIN2(N, M);
		FUP(i, 0, N - 1)
		{
			CIN(p[i]);
			visited[i] = false;
			load[i].clear();
			num[i] = p[i];
		}
		FUP(i, 0, N - 1)
		{
			CIN(h[i]);
		}
		FUP(i, 1, N - 1)
		{
			int a, b;
			CIN2(a, b);
			a--; b--;
			load[a].push_back(b);
			load[b].push_back(a);
		}
		DFS_person(0);
		DFS_check(0);
		answer ? COUT("YES\n") : COUT("NO\n");

	}

	return 0;
}