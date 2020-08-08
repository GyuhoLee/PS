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

	string A, B, answer = "";
	cin >> A >> B;
	if (A.length() < B.length())
	{
		while (A.length() != B.length()) { A = '0' + A; }
	}
	else if (A.length() > B.length())
	{
		while (A.length() != B.length()) { B = '0' + B; }
	}
	int c = 0;
	FDOWN(i, A.length() - 1, 0)
	{
		int a = A[i] - '0';
		int b = B[i] - '0';
		int num = a + b + c;
		if (num >= 10)
		{
			c = 1;
			char ch = num - 10 + '0';
			answer += ch;
		}
		else
		{
			c = 0;
			char ch = num + '0';
			answer += ch;
		}
	}
	if (c == 1) answer += '1';
	reverse(ALL(answer));
	cout << answer;


	return 0;
}