#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N, C;
bool visited[2000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(visited, false);
	cin >> N >> C;
	while (N--)
	{
		int num;
		cin >> num;
		if (visited[num]) continue;
		int temp = num;
		while (temp <= C)
		{
			visited[temp] = true;
			temp += num;
		}
	}
	int answer = 0;
	FUP(i, 1, C) if (visited[i]) answer++;
	cout << answer;

	return 0;
}