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

int N, M, arr[100000], sum = 0, ans;

bool can(int K)
{
	int tmp = 0;
	int cnt = 1;
	FUP(i, 0, N - 1)
	{
		if (arr[i] > K) return false;
		tmp += arr[i];
		if (tmp > K)
		{
			cnt++;
			tmp = arr[i];
		}
	}
	return cnt <= M;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(N, M);
	FUP(i, 0, N - 1)
	{
		CIN(arr[i]);
		sum += arr[i];
	}

	int low = 1;
	int high = ans = sum;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (can(mid))
		{
			ans = mid;
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	COUT(ans);

	return 0;
}