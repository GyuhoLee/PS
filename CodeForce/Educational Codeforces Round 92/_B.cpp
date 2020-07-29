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

int N, K, Z, arr[100000], sum[100000];
pair<int, int> two[100000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	CIN(T);
	while (T--)
	{
		CIN3(N, K, Z);
		CIN(arr[0]);
		two[0] = { 0, 0 };
		sum[0] = arr[0];
		FUP(i, 1, N - 1)
		{
			CIN(arr[i]);
			two[i] = { arr[i - 1] + arr[i], i };
			sum[i] = arr[i] + sum[i - 1];
		}
		if (Z * 2 > K) Z = K / 2;
		sort(two, two + N, greater<pair<int, int>>());
		int answer = sum[K];
		FUP(z, 1, Z)
		{
			int num;
			FUP(i, 0, N - 2)
			{
				if (two[i].second <= K - z * 2)
				{
					num = two[i].first;
					break;
				}
			}
			num = max(num, arr[K - z * 2] + arr[K - z * 2 + 1]);
			if (K - z * 2 != 0)
			{
				answer = max(answer, num * z + sum[K - z * 2]);

			}
			else
			{
				answer = max(answer, arr[0] + (arr[0] + arr[1]) * z);
			}
		}
		COUT(answer);
		ENDL;
	}

	return 0;
}