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

	double A, B, C, D;
	cin >> A >> B >> C >> D;
	double sum[4];
	sum[0] = A / C + B / D;
	sum[1] = C / D + A / B;
	sum[2] = D / B + C / A;
	sum[3] = B / A + D / C;
	double max_num = sum[0];
	int max_idx = 0;
	FUP(i, 1, 3)
	{
		if (max_num < sum[i])
		{
			max_num = sum[i];
			max_idx = i;
		}
	}
	cout << max_idx;


	return 0;
}