#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct node {
	int parent = 0;
	int level = 1;
	int left_son;
	int right_son;
	int x;
};

int N;
int input_x = 1;
int root;
int height = 1;
vector<int> min_x(10001, 10001);
vector<int> max_x(10001, -1);
vector<node> arr(10001);
int answer_level = 1;
int answer_width = 1;

void input();
void setting(int a, int b, int c);
void x_setting(int num, int lev);
void find_root(int num);
void find_answer();

int main()
{
	input();
	find_answer();
	printf("%d %d", answer_level, answer_width);

	return 0;
}

void input()
{
	scanf_s("%d", &N);
	int temp;
	for (int i = 1; i <= N; i++)
	{
		int a, b, c;
		scanf_s("%d %d %d", &a, &b, &c);
		setting(a, b, c);
		temp = a;
	}
	find_root(temp);
	x_setting(root, 1);
}

void setting(int a, int b, int c)
{
	arr[a].left_son = b;
	arr[a].right_son = c;
	if (b != -1) arr[b].parent = a;
	if (c != -1) arr[c].parent = a;
}

void find_root(int num)
{
	while (arr[num].parent)
	{
		num = arr[num].parent;
	}
	root = num;
}

void x_setting(int num, int lev)
{
	height = max(height, lev);
	arr[num].level = lev;
	if (arr[num].left_son != -1) x_setting(arr[num].left_son, lev + 1);
	arr[num].x = input_x;
	if (arr[num].x < min_x[arr[num].level]) min_x[arr[num].level] = arr[num].x;
	if (arr[num].x > max_x[arr[num].level]) max_x[arr[num].level] = arr[num].x;
	input_x++;
	if (arr[num].right_son != -1) x_setting(arr[num].right_son, lev + 1);
}

void find_answer()
{
	for (int i = 2; i <= height; i++)
	{
		if (answer_width < max_x[i] - min_x[i] + 1)
		{
			answer_width = max_x[i] - min_x[i] + 1;
			answer_level = i;
		}
	}
}