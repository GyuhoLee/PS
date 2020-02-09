#include <iostream>
#include <algorithm>
#include <string.h>
#include <limits.h>
using namespace std;

int N;
int arr[20][20];
int total = 0;
int answer = INT_MAX;
int area[5];

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			total += arr[i][j];
		}
	}
}

void calc(int y, int x, int d1, int d2)
{
	memset(area, 0, sizeof(area));

	int temp = 0;
	bool meet = false;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j <= x + d1 - temp; j++)
		{
			if (i == y - d1 - 1) meet = true;
			area[1] += arr[i][j];
		}
		if (meet) temp++;
	}

	temp = x + d1 + 1;
	meet = false;
	for (int i = 0; i <= y - d1 + d2; i++)
	{
		for (int j = temp; j < N; j++)
		{
			if (i == y - d1) meet = true;
			area[2] += arr[i][j];
		}
		if (meet) temp++;
	}

	temp = x;
	meet = true;
	for (int i = y; i < N; i++)
	{
		for (int j = 0; j < temp; j++)
		{
			if (i == y + d2) meet = false;
			area[3] += arr[i][j];
		}
		if (meet) temp++;
	}

	temp = x + d1 + d2;
	meet = true;
	for (int i = y - d1 + d2 + 1; i < N; i++)
	{
		for (int j = temp; j < N; j++)
		{
			if (i == y + d2 + 1) meet = false;
			area[4] += arr[i][j];
		}
		if (meet) temp--;
	}

	area[0] = total - area[1] - area[2] - area[3] - area[4];

	int iMax = *max_element(area, area + 5);
	int iMin = *min_element(area, area + 5);
	answer = min(answer, iMax - iMin);
}

void solve()
{
	for (int i = 0; i < N ; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int d1 = 1; d1 <= i; d1++)
			{
				for (int d2 = 1; d2 < N - i; d2++)
				{
					if (j + d1 + d2 >= N) break;
					calc(i, j, d1, d2);
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	calc(4, 2, 2, 1);
	solve();
	cout << answer;

	return 0;
}