#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<int> arr(100);
vector<int> now;
vector<int> next_number(100, 10000);
int answer = 0;
int on = 0;

void input();
void concent();
void check(int num, int index);
void next_check(int num, int index, int push_index);
int find_max();

int main()
{
	input();
	concent();
	printf("%d", answer);

	return 0;
}

void input()
{
	scanf_s("%d %d", &N, &K);
	for (int i = 0; i < K; i++)
	{
		scanf_s("%d", &arr[i]);
	}
}

void concent()
{
	for (int i = 0; i < K; i++)
	{
		check(arr[i], i);
	}
}

void check(int num, int index)
{
	for (int i = 0; i < on; i++)
	{
		if (now[i] == num)
		{
			next_check(num, index, i);
			return;
		}
	}
	if (on < N)
	{
		now.push_back(num);
		next_check(num, index, now.size() - 1);
		on++;
		return;
	}

	answer++;
	int change = find_max();
	now[change] = num;
	next_check(num, index, change);

}

void next_check(int num, int index, int push_index)
{
	for (int i = index + 1; i < K; i++)
	{
		if (arr[i] == num)
		{
			next_number[push_index] = i;
			return;
		}
	}
	next_number[push_index] = 10000;
}

int find_max()
{
	int num = -1;
	int index;
	for (int i = 0; i < N; i++)
	{
		if (next_number[i] == 10000)
		{
			return i;
		}
		if (num < next_number[i])
		{
			index = i;
			num = next_number[i];
		}
	}
	return index;
}