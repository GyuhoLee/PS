#include <iostream>
using namespace std;

int N, arr[20];
bool num[2000002];

void solve(int i, int sum)
{
	num[sum] = true;
	if (i == N) return;
	solve(i + 1, sum);
	solve(i + 1, sum + arr[i]);
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	solve(0, 0);
	for (int i = 1; i <= 2000001; i++)
	{
		if (!num[i])
		{
			cout << i;
			break;
		}
	}
	
	return 0;
}