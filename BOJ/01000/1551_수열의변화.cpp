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

	int arr[20];
	int N, K;
	cin >> N >> K;
	FUP(i, 0, N - 2)
	{
		char temp;
		cin >> arr[i] >> temp;
	}
	cin >> arr[N - 1];

	while (K--)
	{
		FUP(i, 0, N - 1)
		{
			arr[i] = arr[i + 1] - arr[i];
		}
		N--;
	}
	FUP(i, 0, N - 2)
	{
		cout << arr[i] << ',';
	}
	cout << arr[N - 1];

	return 0;
}