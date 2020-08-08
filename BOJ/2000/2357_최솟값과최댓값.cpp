#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N, M, H = 1;
int a, b;
pair<int, int> Tree[262145];

void solve(int s, int e)
{
	pair<int, int> answer = { 1000000001, -1 };
	while (s <= e)
	{
		if (s % 2)
		{
			answer.first = min(answer.first, Tree[s].first);
			answer.second = max(answer.second, Tree[s].second);
		}
		if (!(e % 2))
		{
			answer.first = min(answer.first, Tree[e].first);
			answer.second = max(answer.second, Tree[e].second);
		}
		s = (s + 1) / 2;
		e = (e - 1) / 2;
	}
	cout << answer.first << ' ' << answer.second << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	while (H < N) { H *= 2; }
	FUP(i, 0, N - 1)
	{
		cin >> Tree[H + i].first;
		Tree[H + i].second = Tree[H + i].first;
	}
	FUP(i, N, H - 1)
	{
		Tree[H + i].second = -1;
		Tree[H + i].first = 1000000001;
	}
	FDOWN(i, H - 1, 1)
	{
		Tree[i].second = max(Tree[i * 2].second, Tree[i * 2 + 1].second);
		Tree[i].first = min(Tree[i * 2].first, Tree[i * 2 + 1].first);
	}

	while (M--)
	{
		cin >> a >> b;
		solve(H + a - 1, H + b - 1);
	}


	return 0;
}