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

string str;
int N, num, idx = 1;
map<char, double> ht;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	CIN2(N, str);
	FUP(i, 0, N - 1)
	{
		CIN(num);
		ht['A' + i] = num;
	}
	stack<char> S;
	for (char ch : str)
	{
		if (ch < 'A' || ch > 'Z')
		{
			double second = ht[S.top()];
			S.pop();
			double first = ht[S.top()];
			S.pop();
			switch (ch)
			{
			case '+': first += second; break;
			case '-': first -= second; break;
			case '*': first *= second; break;
			case '/': first /= second; break;
			}
			S.push(idx);
			ht[idx++] = first;
		}
		else S.push(ch);
	}
	printf("%.2lf", ht[S.top()]);

	return 0;
}