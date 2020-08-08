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

	char arr[50][50];
	int N, M;
	cin >> N >> M;
	int nCnt = 0, mCnt = 0;
	FUP(i, 0, N - 1)
	{
		bool ok = false;
		FUP(j, 0, M - 1)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'X') ok = true;
		}
		if (!ok) nCnt++;
	}
	FUP(j, 0, M - 1)
	{
		bool ok = false;
		FUP(i, 0, N - 1)
		{
			if (arr[i][j] == 'X') ok = true;
		}
		if (!ok) mCnt++;
	}
	cout << max(nCnt, mCnt);


	return 0;
}