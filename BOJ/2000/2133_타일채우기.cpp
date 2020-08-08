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
int arr[16];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	if (N % 2 )
	{
		cout << 0;
		return 0;
	}
	arr[0] = 1;
	arr[1] = 3;
	FUP(i, 2, 15)
	{
		arr[i] = arr[i - 1] * 3;
		FUP(j, 2, i) arr[i] += arr[i - j] * 2;
	}
	cout << arr[N / 2];

	return 0;
}