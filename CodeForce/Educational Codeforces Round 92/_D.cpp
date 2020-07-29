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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	CIN(T);
	while (T--)
	{
		int N, K;
		pair<int, int> point[2];
		CIN2(N, K);
		FUP(i, 0, 1) CIN2(point[i].first, point[i].second);
		sort(point, point + 2);
		int answer = 0;
		int temp = point[0].second - point[1].first;
		if (temp >= 0)
		{
			K -= (temp * N);
			if (K <= 0)
			{
				COUT("0\n");
				continue;
			}
			int num = abs(point[1].second - point[0].second) + point[1].first - point[0].first;
			answer += (num * N);
			K -= answer;
			if (K <= 0)
			{
				answer += K;
			}
			else
			{
				answer += (2 * K);
			}
			COUT(answer);
			ENDL;
		}
		else
		{
			temp *= -1;
			FUP(i, 1, N)
			{
				answer += temp;
				int num = point[1].second - point[0].first;
				answer += num;
				K -= num;
				if (K <= 0)
				{
					answer += K;
					break;
				}
				if (temp >= num)
				{
					answer += (2 * K);
					K = 0;
					break;
				}

			}

			if (K > 0)
			{
				answer += (2 * K);
			}
			COUT(answer);
			ENDL;
		}

	}

	return 0;
}