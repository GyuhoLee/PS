#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define ENDL '\n'
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string S;
	cin >> S;
	int L = S.length();
	FUP(len, L, 2 * L)
	{
		bool OK = true;
		FUP(i, len / 2, L - 1)
		{
			if (S[i] != S[len - i - 1])
			{
				OK = false;
				break;
			}
		}
		if (OK)
		{
			cout << len;
			return 0;
		}
	}

	return 0;
}