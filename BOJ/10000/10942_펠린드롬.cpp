#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[2001];
int answer[2001][2001];
int S, E;

int solve(int start, int finish)
{
	if (answer[start][finish] != -1) return answer[start][finish];
	if (start == finish)
	{
		answer[start][finish] = 1;
		return answer[start][finish];
	}
	if (start + 1 == finish)
	{
		if (arr[start] == arr[finish]) answer[start][finish] = 1;
		else answer[start][finish] = 0;
		return answer[start][finish];
	}
	else
	{
		if (arr[start] != arr[finish])
		{
			answer[start][finish] = 0;
			return answer[start][finish];
		}
		if (solve(start + 1, finish - 1))
		{
			answer[start][finish] = 1;
			return answer[start][finish];
		}
		else
		{
			answer[start][finish] = 0;
			return answer[start][finish];
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	memset(answer, -1, sizeof(answer));
	cin >> M;
	while (M--)
	{
		cin >> S >> E;
		cout << solve(min(S, E), max(S, E)) << '\n';
	}

	return 0;
}