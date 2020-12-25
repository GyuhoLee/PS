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

int N, arr[101];
bool visited[101], now[101];
vector<int> ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	FUP(i, 1, N) CIN(arr[i]);
	FUP(i, 1, N)
	{
		if (visited[i]) continue;
		MS(now, false);
		queue<int> q;
		q.push(i);
		int last = 0;
		while (!q.empty())
		{
			int node = q.front();
			now[node] = true;
			visited[node] = true;
			q.pop();
			int next = arr[node];
			if (visited[next])
			{
				if (now[next]) last = next;
				break;
			}
			q.push(next);

		}
		if (!last) continue;
		int node = last;
		while (true)
		{
			ans.push_back(node);
			if (arr[node] == last) break;
			node = arr[node];
		}
	}
	COUT(ans.size());
	ENDL;
	sort(ALL(ans));
	for (int num : ans)
	{
		COUT(num);
		ENDL;
	}

	return 0;
}