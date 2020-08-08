#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define CIN1(a) cin >> a;
#define CIN2(a, b) cin >> a >> b
#define CIN3(a, b, c) cin >> a >> b >> c
#define COUT1(a) cout << a
#define COUT2(a, b) cout << a << ' ' << b
#define COUT3(a, b, c) cout << a << ' ' << b << ' ' << c
#define ENDL cout << '\n'
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll temp = 0, result = 0; 
	int N, jump = 1;
	CIN1(N);
	string str;
	CIN1(str);
	FDOWN(i, N - 1, 0)
	{ 
		if (str[i] >= '0' && str[i] <= '9')
		{ 
			temp += ((str[i] - '0') * jump);
			jump *= 10; 
		} 
		if (i == 0 || (str[i] < '0' || str[i] > '9'))
		{ 
			result += temp;
			temp = 0; 
			jump = 1; 
		} 
	} 
	COUT1(result);

    return 0;


}