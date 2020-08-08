#include <bits/stdc++.h>
using namespace std;

int arr[4];
int K;
int answer = 0;

void turn(int num, int direct)
{
	if (direct == 1)
	{
		int temp = arr[num] % 2;
		arr[num] = (arr[num] >> 1);
		if (temp) arr[num] += (1 << 7);
	}
	else
	{
		int temp = arr[num] & (1 << 7);
		arr[num] = (arr[num] << 1) % (1 << 8);
		if (temp) arr[num] += 1;
	}
}

void turnLeft(int num, int direct)
{
	if (num < 0) return;
	bool check1 = false, check2 = false;
	if (arr[num + 1] & (1 << 1)) check1 = true;
	if (arr[num] & (1 << 5)) check2 = true;
	if (check1 != check2)
	{
		turnLeft(num - 1, -direct);
		turn(num, direct);
	}
}

void turnRight(int num, int direct)
{
	if (num > 3) return;
	bool check1 = false, check2 = false;
	if (arr[num] & (1 << 1)) check1 = true;
	if (arr[num - 1] & (1 << 5)) check2 = true;
	if (check1 != check2)
	{
		turnRight(num + 1, -direct);
		turn(num, direct);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 4; i++)
	{
		arr[i] = 0;
		int temp;
		cin >> temp;
		for (int j = 0; j < 8; j++)
		{
			if (temp % 10) arr[i] += (1 << j);
			temp /= 10;
			if (!temp) break;
		}
	}
	cin >> K;
	while (K--)
	{
		int a, b;
		cin >> a >> b;
		a--;
		turnLeft(a - 1, -b);
		turnRight(a + 1, -b);
		turn(a, b);
	}
	for (int i = 0; i < 4; i++)
	{
		if (arr[i] & (1 << 7))
		{
			answer += (1 << i);
		}
	}
	cout << answer;


	return 0;
}