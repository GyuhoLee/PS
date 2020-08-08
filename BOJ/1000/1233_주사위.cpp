#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define CIN1(a) cin >> a;
#define CIN2(a, b) cin >> a >> b
#define CIN3(a, b, c) cin >> a >> b >> c
#define COUT1(a) cout << a
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

	int num[81];
	MS(num, 0);
	int S1, S2, S3;
	CIN3(S1, S2, S3);
	FUP(i, 1, S1)
	{
		FUP(j, 1, S2)
		{
			FUP(k, 1, S3)
			{
				num[i + j + k]++;
			}
		}
	}
	int max_num = 0;
	int max_idx = 0;
	FUP(i, 3, 80)
	{
		if (max_num < num[i])
		{
			max_num = num[i];
			max_idx = i;
		}
	}
	COUT1(max_idx);

	return 0;
}