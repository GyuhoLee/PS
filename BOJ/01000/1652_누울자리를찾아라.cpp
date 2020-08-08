#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N;
char arr[100][100];
int garo = 0, sero = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	FUP(i, 0, N - 1)
	{
		FUP(j, 0, N - 1)
			cin >> arr[i][j];
	}

	FUP(i, 0, N - 1)
	{
		int cont = 0;
		FUP(j, 0, N - 1)
		{
			if (arr[i][j] == '.') cont++;
			else
			{
				if (cont >= 2) garo++;
				cont = 0;
			}
		}
		if (cont >= 2) garo++;
	}
	FUP(j, 0, N - 1)
	{
		int cont = 0;
		FUP(i, 0, N - 1)
		{
			if (arr[i][j] == '.') cont++;
			else
			{
				if (cont >= 2) sero++;
				cont = 0;
			}
		}
		if (cont >= 2) sero++;
	}
	cout << garo << ' ' << sero;


	return 0;
}