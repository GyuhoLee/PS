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
#define SIZE 1001

int N, M, K, S, E;
int inDegree[SIZE], cnt[SIZE], num[SIZE];
bool go[SIZE];
vector<int> v[SIZE];
queue<int> q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(inDegree, 0);
	MS(cnt, 0);
	MS(num, 0);
	MS(go, false);
	CIN2(N, M);
	while (M--)
	{
		int a, b;
		CIN2(a, b);
		v[a].push_back(b);
		inDegree[b]++;
	}
	CIN3(S, E, K);
	FUP(i, 1, K)
	{
		int temp;
		CIN(temp);
		go[temp] = true;
	}
	num[S] = 1;
	FUP(i, 0, N - 1)
	{
		if (!inDegree[i]) q.push(i);
	}
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		if (go[node]) cnt[node]++;
		for (int idx : v[node])
		{
			if (cnt[node] == cnt[idx]) num[idx] += num[node];
			else if (cnt[node] > cnt[idx])
			{
				cnt[idx] = cnt[node];
				num[idx] = num[node];
			}
			if (--inDegree[idx] == 0) q.push(idx);
		}
	}
	cnt[E] == K ? COUT(num[E]) : COUT(0);


	return 0;
}