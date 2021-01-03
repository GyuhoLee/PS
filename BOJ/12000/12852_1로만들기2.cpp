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

int N, before[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(before, 0);
	CIN(N);
	queue<int> q;
	q.push(N);
	while (!q.empty())
	{
		int num = q.front();
		q.pop();
		if (num % 3 == 0 && !before[num / 3]) 
		{
			q.push(num / 3);
			before[num / 3] = num;
		}
		if (num % 2 == 0 && !before[num / 2])
		{
			q.push(num / 2);
			before[num / 2] = num;
		}
		if (num > 1 && !before[num - 1])
		{
			q.push(num - 1);
			before[num - 1] = num;
		}
	}
	stack<int> S;
	int num = 1;
	while (num)
	{
		S.push(num);
		num = before[num];
	}
	COUT(S.size() - 1);
	ENDL;
	while (!S.empty())
	{
		COUT2(S.top(), "");
		S.pop();
	}

	return 0;
}