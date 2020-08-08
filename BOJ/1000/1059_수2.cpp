#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

bool arr[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(arr, false);
	int L;
	cin >> L;
	while (L--)
	{
		int temp;
		cin >> temp;
		arr[temp] = true;
	}

	int Left = 0, Right = 0;
	int N;
	cin >> N;
	if (arr[N])
	{
		cout << 0;
		return 0;
	}
	FDOWN(i, N - 1, 1)
	{
		if (arr[i]) break;
		Left++;
	}
	FUP(i, N + 1, 1000)
	{
		if (arr[i]) break;
		Right++;
	}
	cout << Left + Right + Left * Right;

	return 0;
}