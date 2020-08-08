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

	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		if (N == 1)
		{
			cout << "#\n\n";
			continue;
		}
		FUP(i, 0, N - 1) cout << '#';
		cout << '\n';
		FUP(i, 1, N - 2)
		{
			cout << '#';
			FUP(j, 1, N - 2) cout << 'J';
			cout << "#\n";
		}
		FUP(i, 0, N - 1) cout << '#';
		cout << "\n\n";
	}


	return 0;
}