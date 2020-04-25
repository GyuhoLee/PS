#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int arr[200001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		string answer = "YES";
		int N;
		cin >> N;
		FUP(i, 1, N)
		{
			int num;
			cin >> num;
			arr[num] = i;
		}
		int M = N;
		int beforeM = N;
		int first = arr[1];
		if (arr[1] == N) M = N - 1;
		FUP(i, 2, N)
		{
			if (arr[i - 1] == beforeM)
			{
				first = arr[i];
				beforeM = M;
				M = first - 1;
				continue;
			}
			if (arr[i] != arr[i - 1] + 1)
			{
				answer = "NO";
				break;
			}
			if (arr[i] == M)
			{
				M = first - 1;
			}
		}
		cout << answer << '\n';
	}

	return 0;
}