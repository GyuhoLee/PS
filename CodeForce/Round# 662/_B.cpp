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

int N, Q, four = 0, two = 0;
map<int, int> M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	while (N--)
	{
		int num;
		CIN(num);
		if (M.count(num))
		{
			M[num]++;
			if (M[num] % 2 == 0) two++;
			if (M[num] % 4 == 0) four++;
		}
		else M[num] = 1;
	}
	CIN(Q);
	while (Q--)
	{
		char ch;
		int num;
		CIN2(ch, num);
		if (ch == '+')
		{
			if (M.count(num))
			{
				M[num]++;
				if (M[num] % 2 == 0) two++;
				if (M[num] % 4 == 0) four++;
			}
			else M[num] = 1;
		}
		else
		{
			M[num]--;
			if (M[num] % 2 == 1) two--;
			if (M[num] % 4 == 3) four--;
		}

		if (four > 0 && two >= 4) COUT("YES\n");
		else COUT("NO\n");
	}

	

	return 0;
}