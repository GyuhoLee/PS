#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0) return a;
	else gcd(b, a % b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	long long int N, M, P;
	cin >> N >> M >> P;
	long long int arr[1000000];
	long long int arr2[1000000];
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < M; i++) cin >> arr2[i];
	long long int cnt = 0;
	while (cnt <= N + M - 2)
	{
		long long int num = 0;
		for (int i = 0; i < N; i++)
		{
			if (i >= N ||  cnt - i < 0) break;
			if (cnt - i >= M) continue;
			num += (arr[i] * arr2[cnt - i]);
		}
		if (num % P != 0)
		{
			cout << cnt;
			break;
		}
		cnt++;
	}
	

	return 0;
}