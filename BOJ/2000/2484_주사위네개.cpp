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

	int N;
	cin >> N;
	int answer = 0;
	while (N--)
	{
		int arr[4], num;
		FUP(i, 0, 3) cin >> arr[i];
		sort(arr, arr + 4);
		if (arr[0] == arr[3])
		{
			num = 50000 + arr[0] * 5000;
		}
		else if (arr[0] == arr[2] || arr[1] == arr[3])
		{
			num = 10000 + arr[2] * 1000;
		}
		else if (arr[0] == arr[1] && arr[2] == arr[3])
		{
			num = 2000 + (arr[0] + arr[2]) * 500;
		}
		else if (arr[0] != arr[1] && arr[1] != arr[2] && arr[2] != arr[3])
		{
			num = arr[3] * 100;
		}
		else
		{
			int idx = 1;
			if (arr[2] == arr[3]) idx = 2;
			num = 1000 + arr[idx] * 100;
		}
		answer = max(num, answer);
	}
	cout << answer;

    return 0;
}