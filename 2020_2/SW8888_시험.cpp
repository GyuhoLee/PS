#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int TC, N, T, P;
int arr[2000];
bool solve[2000][2000];
pair<pair<int, int>, int> answer[2000];
pair<int, int> ret;

void input()
{
	scanf_s("%d %d %d", &N, &T, &P);
	memset(arr, 0, sizeof(arr));
	for (int i = 0; i < N; i++)
	{
		answer[i].first.second = 0;
		answer[i].second = i;
		for (int j = 0; j < T; j++)
		{
			getchar();
			char temp = getchar();
			if (temp == '0') solve[i][j] = false;
			else solve[i][j] = true;
			if (!solve[i][j]) arr[j]++;
			else answer[i].first.second++;
		}
	}
}

bool cmp(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2)
{
	if (p1.first.first == p2.first.first)
	{
		if (p1.first.second == p2.first.second)
		{
			return p1.second < p2.second;
		}
		else
		{
			return p1.first.second > p2.first.second;
		}
	}
	else
	{
		return p1.first.first > p2.first.first;
	}
}

void check()
{
	for (int i = 0; i < N; i++)
	{
		answer[i].first.first = 0;
		for (int j = 0; j < N; j++)
		{
			if (solve[i][j]) answer[i].first.first += arr[j];
		}
	}
	sort(answer, answer + N, cmp);
	for (int i = 0; i < N; i++)
	{
		if (answer[i].second == P - 1)
		{
			ret.first = answer[i].first.first;
			ret.second = i + 1;
		}
	}
}

int main(int argc, char** argv)
{
	scanf_s("%d", &TC);
	for (int test = 1; test <= TC; test++)
	{
		input();
		check();
		printf("#%d %d %d\n", test, ret.first, ret.second);
	}

	return 0;
}