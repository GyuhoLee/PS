#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

ll arr[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	arr[1] = 1;
	FUP(i, 2, 10000)
	{
		arr[i] = arr[i - 1];
		FUP(k, 1, sqrt(i))
		{
			if (i % k == 0) arr[i]++;
		}
	}
	int N;
	cin >> N;
	cout << arr[N];

	return 0;
}