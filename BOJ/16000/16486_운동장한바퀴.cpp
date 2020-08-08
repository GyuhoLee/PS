#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define ENDL '\n'
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

	double d1, d2;
	cin >> d1 >> d2;
	double answer = d1 * 2 + d2 * 2 * 3.141592;
	printf("%.6lf", answer);

	return 0;
}