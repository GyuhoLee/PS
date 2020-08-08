#include <iostream>
#include <algorithm>
using namespace std;

int N;
int before[2][3] = { 0, 0, 0, 0, 0, 0 };
int d[2][3];
int arr[3];

void solve()
{
	cin >> N;
	while (N--)
	{
		cin >> arr[0] >> arr[1] >> arr[2];

		d[0][0] = max(before[0][0], before[0][1]) + arr[0];
		d[0][1] = max(before[0][0], max(before[0][1], before[0][2])) + arr[1];
		d[0][2] = max(before[0][1], before[0][2]) + arr[2];

		d[1][0] = min(before[1][0], before[1][1]) + arr[0];
		d[1][1] = min(before[1][0], min(before[1][1], before[1][2])) + arr[1];
		d[1][2] = min(before[1][1], before[1][2]) + arr[2];

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				before[i][j] = d[i][j];
			}
		}
	}
	printf("%d %d", max(d[0][0], max(d[0][1], d[0][2])), min(d[1][0], min(d[1][1], d[1][2])));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();

	return 0;
}