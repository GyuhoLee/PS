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

	int N, K;
	cin >> N >> K;
	int answer = N;
	FUP(i, 2, K)
	{
		int num = N * i;
		if (num < 10) answer = num;
		else
		{
			string str = to_string(num);
			reverse(ALL(str));
			answer = max(answer, stoi(str));
		}
	}
	cout << answer;

	return 0;
}