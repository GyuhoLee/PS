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
	
	string A, B;
	cin >> A >> B;
	ll answer = 0;
	FUP(i, 0, A.size() - 1)
	{
		FUP(j, 0, B.size() - 1)
		{
			answer += ((int)(A[i] - '0') * (int)(B[j] - '0'));
		}
	}
	cout << answer;

	return 0;
}