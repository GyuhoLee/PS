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
int before[100000];
int before2[100000];
int after[100000];
int cnt = 0, cnt2 = 1;

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

	cin >> N;
	FUP(i, 0, N - 1)
	{
		scanf_s("%1d", &before[i]);
		before2[i] = before[i];
	}
	FUP(i, 0, N - 1) scanf_s("%1d", &after[i]);

	FUP(i, 1, N - 2)
	{
		if (before[i - 1] != after[i - 1])
		{
			cnt++;
			before[i - 1] = (before[i - 1] + 1) % 2;
			before[i] = (before[i] + 1) % 2;
			before[i + 1] = (before[i + 1] + 1) % 2;
		}
	}
	if (before[N - 1] == after[N - 1])
	{
		if (before[N - 2] != after[N - 2]) cnt = 111111;
	}
	else
	{
		if (before[N - 2] != after[N - 2]) cnt++;
		else cnt = 111111;
	}


	before2[0] = (before2[0] + 1) % 2;
	before2[1] = (before2[1] + 1) % 2;
	FUP(i, 1, N - 2)
	{
		if (before2[i - 1] != after[i - 1])
		{
			cnt2++;
			before2[i - 1] = (before2[i - 1] + 1) % 2;
			before2[i] = (before2[i] + 1) % 2;
			before2[i + 1] = (before2[i + 1] + 1) % 2;
		}
	}
	if (before2[N - 1] == after[N - 1])
	{
		if (before2[N - 2] != after[N - 2]) cnt2 = 111111;
	}
	else
	{
		if (before2[N - 2] != after[N - 2]) cnt2++;
		else cnt2 = 111111;
	}

	int answer = min(cnt, cnt2);
	if (answer > 100000) cout << -1;
	else cout << answer;

	return 0;
}