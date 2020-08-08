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

	int Y = 0, M = 0;
	int N;
	cin >> N;
	while(N--)
	{
		int num;
		cin >> num;
		int yc = num / 30 + 1;
		int mc = num / 60 + 1;
		Y += yc;
		M += mc;
	}
	Y *= 10;
	M *= 15;
	if (Y == M) cout << "Y M " << Y;
	else if (Y > M) cout << "M " << M;
	else cout << "Y " << Y;

	return 0;
}