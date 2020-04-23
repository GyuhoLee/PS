#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N, K, cnt = 0;
bool visited[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(visited, false);
	cin >> N >> K;
	FUP(i, 2, N)
	{
		if (visited[i]) continue;
		int num = i;
		while (num <= N)
		{
			if (visited[num])
			{
				num += i;
				continue;
			}
			visited[num] = true;
			cnt++;
			if (cnt == K)
			{
				cout << num;
				return 0;
			}
			num += i;
		}
	}

	return 0;
}