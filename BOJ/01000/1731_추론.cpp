#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define ENDL '\n'
#define CIN1(a) cin >> a;
#define CIN2(a, b) cin >> a >> b
#define CIN3(a, b, c) cin >> a >> b >> c
#define COUT1(a) cout << a
#define COUT2(a, b) cout << a << ' ' << b
#define COUT3(a, b, c) cout << a << ' ' << b << ' ' << c
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	int arr[50];
	CIN1(N);
	FUP(i, 0, N - 1) CIN1(arr[i]);
	if (arr[2] - arr[1] == arr[1] - arr[0])
	{
		COUT1(arr[N - 1] + arr[2] - arr[1]);
	}
	else
	{
		COUT1(arr[N - 1] * (arr[2] / arr[1]));
	}



    return 0;


}