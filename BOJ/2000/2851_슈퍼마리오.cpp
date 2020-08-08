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
	
	int arr[10];
	FUP(i, 0, 9) cin >> arr[i];
	int total = 0;
	int i = 0;
	for (; i < 10; i++)
	{
		total += arr[i];
		if (total >= 100) break;
	}
	if (total <= 100 || i == 0)
	{
		cout << total;
		return 0;
	}
	if (total - 100 > 100 - total + arr[i])
	{
		cout << total - arr[i];
	}
	else cout << total;

	return 0;
}