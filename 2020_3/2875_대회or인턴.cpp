#include <bits/stdc++.h>
using namespace std;
int N, M, K;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	while (K > 0)
	{
		if (M * 2 < N)
		{
			K = K - (N - M * 2);
			N = M * 2;
		}
		else if (M * 2 > N)
		{
			while (M * 2 > N)
			{
				K--;
				M--;
			}
		}
		else
		{
			N -= 2;
			M--;
			K -= 3;
		}
	}
	if (M * 2 > N) cout << N / 2;
	else cout << M;


	return 0;
}