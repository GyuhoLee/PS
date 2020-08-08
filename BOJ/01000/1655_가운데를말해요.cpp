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

int N;
priority_queue<int> Left;
priority_queue<int, vector<int>, greater<int>> Right;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	while (N--)
	{
		int num;
		CIN(num);
		if (Left.size() > Right.size()) Right.push(num);
		else Left.push(num);

		if (!Right.empty() && Left.top() > Right.top())
		{
			int l = Left.top(), r = Right.top();
			Left.pop();
			Right.pop();
			Left.push(r);
			Right.push(l);
		}

		COUT(Left.top());
		ENDL;
	}

	return 0;
}