#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K;
int arr[301][301];

void input()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> arr[i][j];
		}
	}
	cin >> K;
}

void solve()
{
	int a, b, c, d, answer = 0;;
	cin >> a >> b >> c >> d;
	for (int i = a; i <= c; i++)
	{
		for (int j = b; j <= d; j++)
		{
			answer += arr[i][j];
		}
	}
	printf("%d\n", answer);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	input();
	while (K--)
	{
		solve();
	}

	return 0;
}