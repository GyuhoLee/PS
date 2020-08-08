#include <iostream>
#include <algorithm>
using namespace std;

int N, S;
int arr[20];
int answer = 0;

void input()
{
	cin >> N >> S;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
}

void solve(int num, int sum)
{
	if (num == N)
	{
		if (sum == S)
		{
			answer++;
		}
		return;
	}
	solve(num + 1, sum + arr[num]);
	solve(num + 1, sum);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	solve(0, 0);
	if (!S) answer--;
	cout << answer;

	return 0;
}