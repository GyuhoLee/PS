#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define CIN(a) cin >> a;
#define CIN2(a, b) cin >> a >> b
#define CIN3(a, b, c) cin >> a >> b >> c
#define COUT(a) cout << a
#define COUT2(a, b) cout << a << ' ' << b
#define COUT3(a, b, c) cout << a << ' ' << b << ' ' << c
#define ENDL cout << '\n'
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int arr[1000][1000], y, x, N, ans, i, j, num;

void draw(int cnt, int cnt2)
{
	FUP(i, cnt, cnt + cnt2 - 1)
	{
		arr[i][cnt] = num--;
	}
	if (num == 0) return;
	FUP(i, cnt + 1, cnt + cnt2 - 1)
	{
		arr[cnt + cnt2 - 1][i] = num--;
	}
	
	FDOWN(i, cnt + cnt2 - 2, cnt)
	{
		arr[i][cnt + cnt2 - 1] = num--;
	}
	FDOWN(i, cnt + cnt2 - 2, cnt + 1)
	{
		arr[cnt][i] = num--;
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	num = N * N;
	CIN(ans);
	int cnt2 = N;
	for (int cnt = 1; cnt <= N / 2 + 1; cnt++)
	{
		draw(cnt, cnt2);
		cnt2 -= 2;
	}

	FUP(i, 1, N)
	{
		FUP(j, 1, N)
		{
			if (arr[i][j] == ans)
			{
				y = i;
				x = j;
			}
			COUT2(arr[i][j], "");
		}
		ENDL;
	}
	COUT2(y, x);


	return 0;
}