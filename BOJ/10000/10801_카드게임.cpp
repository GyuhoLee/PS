#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int A[10];
int B[10];
int answer = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	FUP(i, 0, 9) cin >> A[i];
	FUP(i, 0, 9)
	{
		cin >> B[i];
		if (A[i] > B[i]) answer++;
		else if (A[i] < B[i]) answer--;
	}
	if (answer > 0) cout << "A";
	else if (answer == 0) cout << "D";
	else cout << "B";
	

	return 0;
}