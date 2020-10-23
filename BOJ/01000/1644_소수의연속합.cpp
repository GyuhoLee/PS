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

int N, ans = 0;
vector<int> primes;
vector<bool> check;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	check.resize(N + 1, true);
	for (int i = 2; i * i <= N; i++)
	{
		if (!check[i]) continue;
		for (int j = i * i; j <= N; j += i)
		{
			check[j] = false;
		}
	}
	FUP(i, 2, N)
	{
		if (check[i]) primes.push_back(i);
	}

	int left = 0, right = 0, sum = 0;
	while (1)
	{
		if (sum < N)
		{
			if (right == primes.size()) break;
			sum += primes[right++];
		}
		else
		{
			if (sum == N) ans++;
			sum -= primes[left++];
		}
	}
	COUT(ans);


	return 0;
}