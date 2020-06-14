#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N, M, sum = 0;
int i = 0, j = 0;
int answer = 0;
int arr[10000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	FUP(i, 0, N - 1) cin >> arr[i];
	while (true)
	{
		if (sum == M)
		{
			answer++;
			sum -= arr[i];
			i++;
		}
		else if (sum > M)
		{
			sum -= arr[i];
			i++;
		}
		else if (j == N) break;
		else if (sum < M)
		{
			sum += arr[j];
			j++;
		}
	}
	cout << answer;
	return 0;
}