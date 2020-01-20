#include <iostream>
#include <algorithm>
using namespace std;

int arr[10][10];
int block = 0;
int answer = 26;

struct color
{
	int one;
	int two;
	int three;
	int four;
	int five;
	color(int num1, int num2, int num3, int num4, int num5) :one(num1), two(num2), three(num3), four(num4), five(num5) {}
	int use()
	{
		return 25 - (one + two + three + four + five);
	}
};

void input();
void solve(int reamin, int y, int x);
bool check(int num, int y, int x);
void coloring(int num, int y, int x, int in);

color paper(5, 5, 5, 5, 5);


int main()
{
	input();
	solve(block, 0, 0);
	if (answer == 26) printf("-1");
	else printf("%d", answer);

	return 0;
}

void input()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			scanf_s("%d", &arr[i][j]);
			if (arr[i][j]) block++;
		}
	}
}

void solve(int remain, int y, int x)
{
	if (!x && y == 10)
	{
		answer = min(paper.use(), answer);
		return;
	}
	if (!remain)
	{
		answer = min(paper.use(), answer);
		return;
	}
	int nx = x + 1;
	int ny = y;
	if (nx == 10)
	{
		nx = 0;
		ny = y + 1;
	}
	if (!arr[y][x])
	{
		solve(remain, ny, nx);
		return;
	}
	
	if (!check(1, y, x)) return;
	if (paper.one)
	{
		coloring(1, y, x, 0);
		paper.one--;
		solve(remain - 1, ny, nx);
		paper.one++;
		coloring(1, y, x, 1);
	}

	if (!check(2, y, x)) return;
	if (paper.two)
	{
		coloring(2, y, x, 0);
		paper.two--;
		solve(remain - 4, ny, nx);
		paper.two++;
		coloring(2, y, x, 1);
	}

	if (!check(3, y, x)) return;
	if (paper.three)
	{
		coloring(3, y, x, 0);
		paper.three--;
		solve(remain - 9, ny, nx);
		paper.three++;
		coloring(3, y, x, 1);
	}

	if (!check(4, y, x)) return;
	if (paper.four)
	{
		coloring(4, y, x, 0);
		paper.four--;
		solve(remain - 16, ny, nx);
		paper.four++;
		coloring(4, y, x, 1);
	}
	if (!check(5, y, x)) return;
	if (paper.five)
	{
		coloring(5, y, x, 0);
		paper.five--;
		solve(remain - 25, ny, nx);
		paper.five++;
		coloring(5, y, x, 1);
	}
}

bool check(int num, int y, int x)
{
	num--;
	if (y + num > 9 || x + num > 9) return false;
	for (int i = 0; i <= num; i++)
	{
		for (int j = 0; j <= num; j++)
		{
			if(!arr[y + i][x + j]) return false;
		}
	}
	return true;
}

void coloring(int num, int y, int x, int in)
{
	num--;
	for (int i = 0; i <= num; i++)
	{
		for (int j = 0; j <= num; j++)
		{
			arr[y + i][x + j] = in;
		}
	}
}