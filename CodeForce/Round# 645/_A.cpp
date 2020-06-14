#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		int N, M;
		cin >> N >> M;
		if (N % 2 == 0)
		{
			cout << (N / 2) * M << '\n';
		}
		else if (M % 2 == 0)
		{
			cout << (M / 2) * N << '\n';
		}
		else
		{
			if (M > N) swap(N, M);
			cout << N * M / 2 + 1 << '\n';
		}
	}

	return 0;
}