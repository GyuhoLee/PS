#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(long long int i = a; i <= b; i++)
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

	ll A, B;
	cin >> A >> B;
	if (A > B) swap(A, B);
	if (A == B)
	{
		cout << 0;
		return 0;
	}
	cout << B - A - 1 << '\n';
	if (B - A - 1 == 0) return 0;
	FUP(i, A + 1, B - 1)
	{
		cout << i << ' ';
	}

	return 0;
}