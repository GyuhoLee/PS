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

string K, S;
int N;
int dy[8] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dx[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
string direct[8] = { "R", "L", "B", "T", "RT", "LT", "RB", "LB" };
map<string, int> M;
pair<int, int> stone, king;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	FUP(i, 0, 7) M[direct[i]] = i;
	CIN3(K, S, N);
	stone.first = S[1] - '0';
	king.first = K[1] - '0';
	stone.second = S[0] - 'A' + 1;
	king.second = K[0] - 'A' + 1;
	while (N--)
	{
		string str;
		CIN(str);
		int idx = M[str];
		int ny = king.first + dy[idx];
		int nx = king.second + dx[idx];
		if (ny == stone.first && nx == stone.second)
		{
			int nny = ny + dy[idx];
			int nnx = nx + dx[idx];
			if (nny > 8 || nnx > 8 || nny < 1 || nnx < 1) continue;
			stone.first = nny;
			stone.second = nnx;
			king.first = ny;
			king.second = nx;
		}
		else
		{
			if (ny > 8 || nx > 8 || ny < 1 || nx < 1) continue;
			king.first = ny;
			king.second = nx;
		}
	}
	S[0] = stone.second + 'A' - 1;
	S[1] = stone.first + '0';
	K[0] = king.second + 'A' - 1;
	K[1] = king.first + '0';
	COUT(K);
	ENDL;
	COUT(S);

	return 0;
}