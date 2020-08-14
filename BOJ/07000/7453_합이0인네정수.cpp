#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define CIN(a) cin >> a;
#define CIN2(a, b) cin >> a >> b
#define CIN3(a, b, c) cin >> a >> b >> c
#define COUT(a) cout << a
#define COUT2(a, b) cout << a << ' ' << b
#define COUT3(a, b, c) cout << a << ' ' << b << ' ' << c
#define ENDL cout << '\n'
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

ll N, answer = 0;
ll A[4000], B[4000], C[4000], D[4000];
vector<ll> AB, CD;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	FUP(i, 0, N - 1)
	{
		CIN2(A[i], B[i]);
		CIN2(C[i], D[i]);
	}
	AB.resize((N * N));
	CD.resize((N * N));
	FUP(i, 0, N - 1)
	{
		FUP(j, 0, N - 1)
		{
			AB[N * i + j] = A[i] + B[j];
			CD[N * i + j] = C[i] + D[j];
		}
	}
	sort(ALL(AB));
	sort(ALL(CD));
	for (auto num : AB)
	{
		ll upper = upper_bound(ALL(CD), -num) - CD.begin();
		ll lower = lower_bound(ALL(CD), -num) - CD.begin();
		answer += (upper - lower);
	}
	COUT(answer);

	return 0;
}