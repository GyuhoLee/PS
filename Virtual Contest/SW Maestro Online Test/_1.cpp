#include <bits/stdc++.h>
using namespace std;

int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	if (N % 2 == 0)
	{
		for (int i = 0; i < N / 2; i++) cout << 1;
	}
	else
	{
		cout << 7;
		for (int i = 0; i < N / 2 - 1; i++) cout << 1;
	}

	return 0;
}