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

int N, num;
deque<pair<int, int>> dq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	FUP(i, 1, N)
	{
		CIN(num);
		dq.push_back({ num, i });
	}
	N--;
	while (N--)
	{
		num = dq.front().first;
		COUT2(dq.front().second, "");
		if (num > 0)
		{
			dq.pop_front();
			num--;
			while (num--)
			{
				auto tmp = dq.front();
				dq.pop_front();
				dq.push_back(tmp);
			}
		}
		else
		{
			dq.pop_front();
			while (num++)
			{
				auto tmp = dq.back();
				dq.pop_back();
				dq.push_front(tmp);
			}
		}
	}
	COUT(dq.front().second);

	return 0;
}