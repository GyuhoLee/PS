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

int N;
int arr[501];
int num[501];
vector<int> v[501];

int DFS(int node)
{
	if (num[node] != -1) return num[node];
	int cnt = 0;
	for (int i : v[node])
	{
		cnt = max(DFS(i), cnt);
	}
	return num[node] = arr[node] + cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(num, -1);
	CIN(N);
	FUP(i, 1, N)
	{
		CIN(arr[i]);
		while (1)
		{
			int tmp;
			CIN(tmp);
			if (tmp == -1) break;
			v[i].push_back(tmp);
		}
	}
	FUP(i, 1, N)
	{
		if (num[i] == -1)
		{
			DFS(i);
		}
		COUT(num[i]);
		ENDL;
	}

	return 0;
}