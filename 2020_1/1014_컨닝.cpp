#include <iostream>
#include <algorithm>
using namespace std;
int T, N, M;
bool arr[10][10];
char temp;
int answer;

void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> temp;
			arr[i][j] = (temp == '.');
		}
	}
	answer = 0;
}

void sit(int num, int cnt)
{
	if (num == N * M)
	{
		answer = max(cnt, answer);
		return;
	}
	int i = num / M;
	int j = num % M;
	if (arr[i][j])
	{
		arr[i][j] = false;
		sit(num + 1, cnt + 1);
		arr[i][j] = true;
	}
	sit(num + 1, cnt);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--)
	{
		input();
		sit(0, 0);
		printf("%d\n", answer);
	}

	return 0;
}