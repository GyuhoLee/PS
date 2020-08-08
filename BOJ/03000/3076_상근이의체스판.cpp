#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define ENDL '\n'
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int R, C, A, B;
	cin >> R >> C >> A >> B;
	char ch[2] = { 'X', '.' };
	int idx = 0;
	int idx2 = 0;
	FUP(r, 1, R)
	{
		FUP(a, 1, A)
		{
			idx = idx2;
			FUP(c, 1, C)
			{
				FUP(b, 1, B)
				{
					cout << ch[idx];
				}
				idx++;
				idx %= 2;
			}
			cout << ENDL;
		}
		idx2++;
		idx2 %= 2;
	}

	return 0;
}