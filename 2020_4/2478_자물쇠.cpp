#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N;
int arr[500];
int zero = -1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	FUP(i, 0, N - 1)
	{
		cin >> arr[i];
		arr[i]--;
		if (arr[i] == 0) zero = i;
	}
	int p = -1, q = -1;
	FUP(i, 1, N - 1)
	{
		if ((arr[i] == 0 && arr[i - 1] != N - 1) || (arr[i] != 0 && arr[i] - arr[i - 1] != 1))
		{
			if (p == -1) p = i + 1;
			else q = i;
		}
	}
	if ((arr[0] != 0 && arr[0] - arr[N - 1] != 1) || (arr[0] == 0 && arr[N - 1] != N - 1))
	{
		if (p == 2)
		{
			if (q == -1) q = 2;
			p = 1;
		}
		if (q == N - 1)
		{
			q = N;
		}
	}


	cout << N - zero << '\n' << p << ' ' << q << '\n' << N;


	return 0;
}