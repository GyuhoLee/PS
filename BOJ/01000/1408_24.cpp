#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

ll arr[10001];

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

	int h, m, s;
	scanf("%d:%d:%d", &h, &m, &s);
	int cT = s + m * 60 + h * 3600;
	h = m = s = 0;
	scanf("%d:%d:%d", &h, &m, &s);
	int sT = s + m * 60 + h * 3600;
	if (cT > sT) sT += 24 * 60 * 60;
	int sol = sT - cT;
	h = sol / 3600, sol %= 3600;
	m = sol / 60, sol %= 60;
	s = sol;
	printf("%02d:%02d:%02d", h, m, s);

	return 0;

}