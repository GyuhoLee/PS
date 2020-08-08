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

	int N, K;
	cin >> N >> K;
	int arr[2][6];
	MS(arr, 0);
	while (N--)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b - 1]++;
	}
	int answer = 0;
	int num = arr[0][0] + arr[0][1] + arr[1][0] + arr[1][1];
	answer += (num / K);
	if (num % K) answer++;
	for (int i = 2; i < 6; i += 2)
	{
		int num = 0;
		for (int j = 0; j < 2; j++)
		{
			num = arr[j][i] + arr[j][i + 1];
			answer += (num / K);
			if (num % K) answer++;
		}
	}
	cout << answer;


	return 0;
}