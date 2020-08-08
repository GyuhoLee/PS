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

int T, N, num, cnt[100001], max_num, max_cnt;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(T);
	while (T--)
	{
		MS(cnt, 0);
		max_num = 0;
		max_cnt = 0;
		CIN(N);
		int tmp = N;
		while (tmp--)
		{
			CIN(num);
			cnt[num]++;
			if (cnt[num] > max_num)
			{
				max_num = cnt[num];
				max_cnt = 1;
			}
			else if (cnt[num] == max_num) max_cnt++;
		}
		N -= (max_cnt * max_num);
		tmp = N / (max_num - 1);
		COUT(tmp + max_cnt - 1);
		ENDL;
	}

	return 0;
}