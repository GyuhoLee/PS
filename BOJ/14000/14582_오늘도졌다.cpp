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
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

string answer = "No";

int num1 = 0, num2 = 0;
int arr[9], arr2[9];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	FUP(i, 0, 8) CIN(arr[i]);
	FUP(i, 0, 8) CIN(arr2[i]);
	FUP(i, 0, 8)
	{
		num1 += arr[i];
		if (num1 > num2) answer = "Yes";
		num2 += arr2[i];
	}
	COUT(answer);

	return 0;
}