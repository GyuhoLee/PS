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
ll arr[81];
ll answer = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	arr[1] = 1;  arr[2] = 1;
	FUP(i, 3, 80) arr[i] = arr[i - 1] + arr[i - 2];
	int N;
	cin >> N;
	answer = arr[N] * 2 + arr[N - 1];
	cout << answer * 2;

	return 0;
}