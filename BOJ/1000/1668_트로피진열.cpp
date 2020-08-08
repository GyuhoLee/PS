#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define ENDL '\n'
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	int arr[50];
	cin >> N;
	FUP(i, 0, N - 1) cin >> arr[i];

	int answer = 0;
	int now = 0;
	FUP(i, 0, N - 1)
	{
		if (now < arr[i])
		{
			now = arr[i];
			answer++;
		}
	}
	cout << answer << ENDL;

	answer = 0;
	now = 0;
	FDOWN(i, N - 1, 0)
	{
		if (now < arr[i])
		{
			now = arr[i];
			answer++;
		}
	}
	cout << answer;

	return 0;
}