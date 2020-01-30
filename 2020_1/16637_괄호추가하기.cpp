#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <limits.h>
using namespace std;

int N;
int first;
int num[10];
char oper[10];
int answer = INT_MIN;


void input()
{
	cin >> N >> first;
	for (int i = 0; i < N / 2; i++)
	{
		cin >> oper[i] >> num[i];
	}
}

int solve(int a, int b, char c)
{
	switch (c)
	{
	case '+': return a + b;
	case '-': return a - b;
	default: return a * b;
	}
}

void DFS(int idx, int cnt)
{
	if (idx == N / 2)
	{
		answer = max(answer, cnt);
		return;
	}
	int temp = solve(cnt, num[idx], oper[idx]);
	DFS(idx + 1, temp);
	if (idx < (N / 2) - 1)
	{
		temp = solve(num[idx], num[idx + 1], oper[idx + 1]);
		temp = solve(cnt, temp, oper[idx]);
		DFS(idx + 2, temp);
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	DFS(0, first);
	cout << answer;

	return 0;
}