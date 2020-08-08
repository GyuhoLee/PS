#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int arr[1501];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, L;
	cin >> N >> M >> L;
	int arr[1000];
	int idx = 0;
	int answer = -1;
	MS(arr, 0);
	while (1)
	{
		answer++;
		arr[idx]++;
		if (arr[idx] == M) break;
		if (arr[idx] % 2)
		{
			idx += L;
			if (idx >= N) idx -= N;
		}
		else
		{
			idx -= L;
			if (idx < 0) idx += N;
		}
	}
	cout << answer;

	return 0;
}