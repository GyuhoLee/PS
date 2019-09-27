#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int N;
set<int> arr[50];
set<int> arr2[50];
int answer = 0;
void input();
void two();
void find_max();

int main()
{
	input();
	two();
	find_max();

	return 0;
}

void input()
{
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			char temp;
			scanf_s("%c", &temp);
			if (temp == 'Y')
			{
				arr[i].insert(j);
				arr2[i].insert(j);
			}
		}
	}
}

void two()
{
	for (int i = 0; i < N; i++)
	{
		for (auto j = arr[i].begin(); j != arr[i].end(); j++)
		{
			for (auto k = arr[*j].begin(); k != arr[*j].end(); k++)
			{
				if (i == *k) continue;
				arr2[i].insert(*k);
			}
		}
	}
}

void find_max()
{
	for (int i = 0; i < N; i++)
	{
		answer = max(answer, (int)arr2[i].size());
	}
	printf("%d", answer);
}