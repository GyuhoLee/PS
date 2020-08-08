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

	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		cout << "Pairs for " << N << ": ";
		FUP(i, 1, (N + 1) / 2 - 2)
		{
			cout << i << ' ' << N - i << ", ";
		}
		if (N > 2)
		{
			cout << (N + 1) / 2 - 1 << ' ' << N + 1 - (N + 1) / 2;
		}
		cout << ENDL;
	}

	return 0;
}