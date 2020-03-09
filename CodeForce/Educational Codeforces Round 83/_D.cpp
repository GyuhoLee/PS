#include <bits/stdc++.h>
using namespace std;
#define DIV 998244353
#define ll long long int

int N, M;
ll answer = 0;

ll solve(int cnt, int num)
{
	if (cnt > num) return 0;
	if (cnt == num) return 1;
	ll ret = 1;
	ll div = 1;
	while (cnt)
	{
		ret = ret * num % DIV;
		div = div * cnt % DIV;
		num--;
		cnt--;
	}
	ret /= div;
	if (ret < 0) ret = 0;
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 2; i <= N / 2; i++)
	{
		for (int j = M; j >= N - i; j--)
		{
			ll left = solve(i - 1, j - 1) % DIV;
			ll right = (i - 1) * solve(N - i - 1, j - i) % DIV;
			answer += (left * right * 2) % DIV;
		}
	}
	if (N % 2 == 1)
	{
		for (int j = M; j >= M - N; j--)
		{
			ll left = solve(N / 2, j - 1) % DIV;
			ll right = N / 2 * solve(N / 2 - 1, j - N / 2) % DIV;
			answer += (left * right) % DIV;
		}
	}
	cout << answer % DIV;

	return 0;
}