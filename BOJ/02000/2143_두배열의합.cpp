#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define ll long long

ll T, N, M, num, A[1001][1001], B[1001][1001], ans = 0;
map<ll, ll> table;

int main()
{
	cin >> T;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> num;
		for (int j = 1; j <= i; j++)
		{
			A[j][i] = A[j - 1][i - 1] + num;
		}
	}
	cin >> M;
	for (int i = 1; i <= M; i++)
	{
		cin >> num;
		for (int j = 1; j <= i; j++)
		{
			B[j][i] = B[j - 1][i - 1] + num;
			table[B[j][i]]++;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (table.count(T - A[j][i])) ans += table[T - A[j][i]];
		}
	}
	cout << ans;

	return 0;
}