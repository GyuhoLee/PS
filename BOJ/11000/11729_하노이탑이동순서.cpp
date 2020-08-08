#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N, answer = 1;

void hanoi(int num, int s, int e, int left)
{
	if (num == 1)
	{
		cout << s << ' ' << e << '\n';
		return;
	}
	hanoi(num - 1, s, left, e);
	cout << s << ' ' << e << '\n';
	hanoi(num - 1, left, e, s);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	FUP(i, 0, N - 2)
	{
		answer = answer * 2 + 1;
	}
	cout << answer << '\n';

	hanoi(N, 1, 3, 2);

	return 0;
}