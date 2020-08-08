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

	int K, N, time = 0;
	cin >> K >> N;
	while (N--)
	{
		int T;
		char Z;
		cin >> T >> Z;
		time += T;
		if (time >= 210)
		{
			cout << K;
			break;
		}
		if (Z == 'T') K = (K % 8) + 1;
	}




	return 0;
}