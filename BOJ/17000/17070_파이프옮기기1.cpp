#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[18][18];
int answer;
struct node {
	int x;
	int y;
	node(int d_y, int d_x) :x(d_x), y(d_y) {}
	
	//1은 대각선, 2는 가로, 3은 세로
	int direct(node last)
	{
		if (x < last.x && y < last.y) return 1;
		else if (x < last.x) return 2;
		else return 3;
	}
};

void input();
void move(node first, node last);

int main()
{
	input();
	move(node(1, 1), node(1, 2));
	printf("%d", answer);
	
	return 0;
}

void input()
{
	scanf_s("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf_s("%d", &arr[i][j]);
		}
	}
}

//1이면 대각선 2면 가로 3이면 세로
void move(node first, node last)
{
	if (last.x == N && last.y == N)
	{
		answer++;
		return;
	}
	int status = first.direct(last);
	bool check1 = false;
	bool check2 = false;
	switch (status)
	{
	case 1://대각선
		if (last.x + 1 <= N)
		{
			if (!arr[last.y][last.x + 1])
			{
				move(last, node(last.y, last.x + 1));
				check1 = true;
			}
		}
		if (last.y + 1 <= N)
		{
			if(!arr[last.y + 1][last.x])
			{
				move(last, node(last.y + 1, last.x));
				check2 = true;
			}
		}
		if (check1 && check2)
		{
			if (!arr[last.y + 1][last.x + 1])
			{
				move(last, node(last.y + 1, last.x + 1));
			}
		}
		break;
	case 2://가로
		if (last.x < N)
		{
			if (!arr[last.y][last.x + 1])
			{
				move(last, node(last.y, last.x + 1));
				if (last.y < N)
				{
					if (!arr[last.y + 1][last.x] && !arr[last.y + 1][last.x + 1])
					{
						move(last, node(last.y + 1, last.x + 1));
					}
				}
			}
		}
		break;
	case 3://세로
		if (last.y < N)
		{
			if (!arr[last.y + 1][last.x])
			{
				move(last, node(last.y + 1, last.x));
				if (last.x < N)
				{
					if (!arr[last.y][last.x + 1] && !arr[last.y + 1][last.x + 1])
					{
						move(last, node(last.y + 1, last.x + 1));
					}
				}
			}
		}
		break;
	}

}