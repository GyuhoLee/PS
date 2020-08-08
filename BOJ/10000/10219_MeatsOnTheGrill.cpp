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

	int T;
	cin >> T;
	while (T--)
	{
		int H, W;
		cin >> H >> W;
		char arr[11][11];
		FUP(i, 0, H - 1)
		{
			FUP(j, 0, W - 1)
			{
				cin >> arr[i][j];
			}
		}
		FUP(i, 0, H - 1)
		{
			FDOWN(j, W - 1, 0)
			{
				cout << arr[i][j];
			}
			cout << '\n';
		}
	}

	return 0;
}