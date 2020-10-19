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

int N;
vector<int> big, small;
char oper[9];

bool ok()
{
	FUP(i, 0, N)
	{
		if (oper[i] == '<' && big[i] > big[i + 1]) return false;
		else if (oper[i] == '>' && big[i] < big[i + 1]) return false;
	}
	return true;
}
bool ok2()
{
	FUP(i, 0, N)
	{
		if (oper[i] == '<' && small[i] > small[i + 1]) return false;
		else if (oper[i] == '>' && small[i] < small[i + 1]) return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	FUP(i, 0, N - 1) CIN(oper[i]);
	FDOWN(i, 9, 9 - N) big.push_back(i);
	FUP(i, 0, N) small.push_back(i);

	while (true)
	{
		if (ok()) break;
		prev_permutation(ALL(big));
	}
	while (true)
	{
		if (ok2()) break;
		next_permutation(ALL(small));
	}
	for (int num : big)
	{
		COUT(num);
	}
	ENDL;
	for (int num : small)
	{
		COUT(num);
	}

	return 0;
}