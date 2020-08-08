#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int D, N;
int oven[300001];
int pizza[300001];

void input()
{
	cin >> D >> N;
	oven[0] = INT_MAX;
		for (int i = 1; i <= D; i++)
		{
			cin >> oven[i];
			oven[i] = min(oven[i], oven[i - 1]);
		}
	for (int i = 0; i < N; i++) cin >> pizza[i];
}

void solve()
{
	int i = 0;
	for (int j = D; j > 0; j--)
	{
		if (pizza[i] <= oven[j])
		{
			i++;
			if (i == N)
			{
				cout << j;
				return;
			}
		}
	}
	cout << 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();

	return 0;
}