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

int N, arr[1002];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(arr, 0);
	CIN(N);
	while (N--)
	{
		int num;
		CIN(num);
		arr[num]++;
	}
	int idx = 0;
	while (idx <= 1000)
	{
		if (!arr[idx])
		{
			idx++;
			continue;
		}
		if (arr[idx + 1])
		{
			int num = -1;
			FUP(i, idx + 2, 1000)
			{
				if (arr[i])
				{
					num = i;
					break;
				}
			}
			if (num != -1)
			{
				FUP(i, 1, arr[idx]) COUT2(idx, "");
				COUT2(num, "");
				arr[num]--;
			}
			else
			{
				FUP(i, 1, arr[idx + 1]) COUT2(idx + 1, "");
				FUP(i, 1, arr[idx]) COUT2(idx, "");
				idx++;
			}
		}
		else
		{
			FUP(i, 1, arr[idx]) COUT2(idx, "");
		}
		idx++;
	}

	return 0;
}