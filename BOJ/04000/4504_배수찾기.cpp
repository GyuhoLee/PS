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
	//cout.tie(0);

	int N;
	cin >> N;
	while (true)
	{
		int num;
		cin >> num;
		if (!num) break;
		printf("%d is ", num);
		if (num % N) printf("NOT ");
		printf("a multiple of %d.\n", N);
	}

	return 0;
}