#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	int num;
	switch (N % 8)
	{
	case 1: num = 1; break;
	case 5: num = 5; break;
	case 2: case 0: num = 2; break;
	case 3: case 7: num = 3; break;
	default: num = 4; break;
	}
	cout << num;

	return 0;
}