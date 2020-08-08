#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define CIN(a) cin >> a;
#define CIN2(a, b) cin >> a >> b
#define CIN3(a, b, c) cin >> a >> b >> c
#define COUT(a) cout << a
#define COUT2(a, b) cout << a << ' ' << b
#define COUT3(a, b, c) cout << a << ' ' << b << ' ' << c
#define ENDL cout << '\n'
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N, S, arr[100000], sum = 0;
int idx = 0, answer = 111111;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(N, S);
	FUP(i, 0, N - 1)
	{
		CIN(arr[i]);
		sum += arr[i];
	}
	if (sum < S)
	{
		COUT(0);
		return 0;
	}
	int num = 0;
	FUP(i, 0, N - 1)
	{
		if (i) num -= arr[i - 1];
		while (num < S)
		{
			if (idx == N) break;
			num += arr[idx];
			idx++;
		}
		if (num < S) break;
		answer = min(answer, idx - i);
	}
	COUT(answer);


	return 0;
}