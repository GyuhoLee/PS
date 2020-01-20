#include <iostream>
#include <algorithm>
using namespace std;

int N;
struct person {
	int h;
	int w;
	int answer;
	void set(int _h, int _w)
	{
		h = _h;
		w = _w;
		answer = 1;
	}
};
person P[50];

void input();
void solve();

int main()
{
	input();
	solve();

	return 0;
}

void input()
{
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int a, b;
		scanf_s("%d %d", &a, &b);
		P[i].set(a, b);
	}
}

void solve()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == j) continue;
			if (P[i].h < P[j].h && P[i].w < P[j].w) P[i].answer++;
		}
		printf("%d ", P[i].answer);
	}
}