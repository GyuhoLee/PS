#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N, M, K;
int arr[100][100];
int A[100][100];
int B[100][100];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	FUP(i, 0, N - 1)
	{
		FUP(j, 0, M - 1)
		{
			cin >> A[i][j];
		}
	}
	cin >> M >> K;
	FUP(i, 0, M - 1)
	{
		FUP(j, 0, K - 1)
		{
			cin >> B[i][j];
		}
	}
	FUP(i, 0, N - 1)
	{
		FUP(j, 0, K - 1)
		{
			arr[i][j] = 0;
			FUP(k, 0, M - 1)
			{
				arr[i][j] += (A[i][k] * B[k][j]);
			}
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	

	return 0;
}