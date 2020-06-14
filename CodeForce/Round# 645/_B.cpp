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
int arr[100000];
int answer = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		cin >> N;
		int total = N ;
		FUP(i, 0, N - 1) cin >> arr[i];
		sort(arr, arr + N);
		FDOWN(i, N - 1, 0)
		{
			if (total < arr[i])
			{
				total--;
				continue;
			}
			break;
		}
		cout << total + 1 << '\n';
	}

	return 0;
}