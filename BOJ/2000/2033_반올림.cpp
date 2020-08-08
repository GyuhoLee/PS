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
	int temp = 10;
	while (N >= temp)
	{
		if (N % temp >= temp / 2)
		{
			N = (N / temp + 1) * temp;
		}
		else
		{
			N = N / temp * temp;
		}
		temp *= 10;
	}
	cout << N;

    return 0;
}