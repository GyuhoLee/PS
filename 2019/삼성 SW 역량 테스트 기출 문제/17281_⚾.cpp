#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[9][50];
int pmt[8];
int answer = 0;

int idx = 0;
int score = 0;
int out = 0;
int base[3] = { 0, 0, 0 };

void input();
void solve();
void bat(int num);

int main()
{
	input();
	solve();
	printf("%d", answer);
}

void input()
{
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			scanf_s("%d", &arr[j][i]);
		}
	}
	for (int i = 0; i < 8; i++)
		pmt[i] = i + 1;
}

void solve()
{
	do {
		score = 0;
		idx = 0;
		for (int i = 0; i < N; i++)
		{
			out = 0;
			base[0] = 0;
			base[1] = 0;
			base[2] = 0;
			while (out < 3)
			{
				if (idx < 3) bat(arr[pmt[idx]][i]);
				else if (idx == 3) bat(arr[0][i]);
				else bat(arr[pmt[idx - 1]][i]);
				idx = (idx + 1) % 9;
			}
		}
		answer = max(answer, score);
	} while (next_permutation(pmt, pmt + 8));
}

void bat(int num)
{
	switch (num)
	{
	case 0:
		out++;
		break;
	case 1:
		if (base[2])
		{
			score++;
			base[2] = 0;
		}
		if (base[1])
		{
			base[2] = 1;
			base[1] = 0;
		}
		if (base[0])
		{
			base[1] = 1;
		}
		base[0] = 1;
		break;
	case 2:
		if (base[2])
		{
			score++;
			base[2] = 0;
		}
		if (base[1])
		{
			score++;
			base[1] = 0;
		}
		if (base[0])
		{
			base[2] = 1;
			base[0] = 0;
		}
		base[1] = 1;
		break;
	case 3:
		if (base[2])
		{
			score++;
			base[2] = 0;
		}
		if (base[1])
		{
			score++;
			base[1] = 0;
		}
		if (base[0])
		{
			score++;
			base[0] = 0;
		}
		base[2] = 1;
		break;
	case 4:
		if (base[2])
		{
			score++;
			base[2] = 0;
		}
		if (base[1])
		{
			score++;
			base[1] = 0;
		}
		if (base[0])
		{
			score++;
			base[0] = 0;
		}
		score++;
		break;
	}
}