#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N, K;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	int left = 1;
	int right = K;
	int result = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		long long num = 0;
		FUP(i, 1, N) num += min(mid / i, N);
		if (num < K) left = mid + 1;
		else
		{
			result = mid;
			right = mid - 1;
		}

	}
	cout << result;

	return 0;
}