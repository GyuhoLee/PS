#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int K;
pair<int, int> arr[6];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int num = -1;
	int y = -1;
	int x = -1;
	FUP(i, 1, 9)
	{
		FUP(j, 1, 9)
		{
			int temp;
			cin >> temp;
			if (temp > num)
			{
				num = temp;
				y = i;
				x = j;
			}
		}
	}
	cout << num << '\n' << y << ' ' << x;

	return 0;
}