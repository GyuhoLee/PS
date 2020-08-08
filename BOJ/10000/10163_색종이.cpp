#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int arr[101][101];

void cnt(int num)
{
	int ret = 0;
	FUP(i, 0, 100)
	{
		FUP(j, 0, 100)
		{
			if (arr[i][j] == num) ret++;
		}
	}
	cout << ret << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	MS(arr, 0);
	int N;
	cin >> N;
	FUP(k, 1, N)
	{
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		FUP(i, x, x + a - 1)
		{
			FUP(j, y, y + b - 1)
			{
				arr[i][j] = k;
			}
		}
	}
	
	FUP(i, 1, N)
	{
		cnt(i);
	}

	return 0;
}