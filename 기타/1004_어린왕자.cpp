#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct point {
	int x;
	int y;
	int r;
};

int N;
point start;
point finish;
point arr[50];

void input();
void solve();

int main()
{
	int T;
	scanf_s("%d", &T);
	while (T--)
	{
		input();
		solve();
	}
}

void input()
{
	scanf_s("%d %d %d %d", &start.x, &start.y, &finish.x, &finish.y);
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++)
		scanf_s("%d %d %d", &arr[i].x, &arr[i].y, &arr[i].r);
}

void solve()
{
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		int x = arr[i].x;
		int y = arr[i].y;
		int r = arr[i].r;
		if (pow(x - start.x, 2) + pow(y - start.y, 2) < pow(r, 2) && pow(x - finish.x, 2) + pow(y - finish.y, 2) < pow(r, 2))
			continue;
		else if (pow(x - start.x, 2) + pow(y - start.y, 2) < pow(r, 2))
			answer++;
		else if (pow(x - finish.x, 2) + pow(y - finish.y, 2) < pow(r, 2))
			answer++;
	}
	printf("%d\n", answer);
}
