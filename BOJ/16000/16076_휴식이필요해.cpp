#include <iostream>
#include <algorithm>
using namespace std;

int D, N;
int oven[300001];
int pizza[300000];

void input()
{
	cin >> D >> N;
	for (int i = 1; i <= D; i++) cin >> oven[i];
	for (int i = D - 1; i > 0; i--)
	{
		if (oven[i] < oven[i + 1]) oven[i + 1] = oven[i];
	}
	for (int i = 0; i < N; i++) cin >> pizza[i];
}

void solve()
{
	int idx = 0;
	for (int i = D; i > 0; i--)
	{
		if (pizza[idx] > oven[i]) continue;
		idx += 1;
		if (idx == N)
		{
			cout << i;
			return;
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