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

int T, N, arr[100000], answer;
bool visited[100000];
deque<int> dq;

void DFS(int node)
{
	visited[node] = true;
	dq.push_back(node);
	int next = arr[node];
	if (visited[next])
	{
		int cnt = 0;
		while (!dq.empty())
		{
			int num = dq.front();
			dq.pop_front();
			if (num == next) break;
			else cnt++;
		}
		answer += cnt;
		dq.clear();
		return;
	}
	else
	{
		DFS(next);
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
		CIN(N);
		answer = 0;
		MS(visited, false);
		FUP(i, 0, N - 1)
		{
			CIN(arr[i]);
			arr[i]--;
		}
		FUP(i, 0, N - 1)
		{
			if (!visited[i])
			{
				DFS(i);
			}
		}
		COUT(answer);
		ENDL;
	}

	return 0;
}