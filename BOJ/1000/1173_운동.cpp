#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define ENDL '\n'
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, m, M, T, R;
	cin >> N >> m >> M >> T >> R;
	if (m + T > M)
	{
		cout << -1;
		return 0;
	}
	int answer = 0;
	int now = m;
	while (N)
	{
		if (now + T <= M)
		{
			now += T;
			N--;
			answer++;
		}
		else
		{
			now = max(now - R, m);
			answer++;
		}
	}
	cout << answer;

	return 0;
}