#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int answer = 0;
int DP[301][301];

void input()
{
	cin >> N >> M;
}

void solve(int n, int m)
{
	if (n == 1 && m == 1) return;
	if (n > m)
	{
		answer++;
		if (n % 2)
		{
			solve(n / 2, m);
			solve(n / 2 + 1, m);
		}
		else
		{
			solve(n / 2, m);
			solve(n / 2, m);
		}
	}
	else
	{
		answer++;
		if (m % 2)
		{
			solve(n, m / 2);
			solve(n, m / 2 + 1);
		}
		else
		{
			solve(n, m / 2);
			solve(n, m / 2);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();
	solve(N, M);
	printf("%d", answer);

	return 0;
}