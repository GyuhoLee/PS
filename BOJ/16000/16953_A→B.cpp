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

ll A, B;
map<int, int> table;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(A, B);
	priority_queue<pair<int, int>> pq;
	pq.push({ -1, A });
	table[A] = 1;
	while (!pq.empty())
	{
		int num = -pq.top().first;
		ll idx = pq.top().second;
		pq.pop();
		if (idx == B) break;
		ll next = idx * 2;
		if (next <= B && !table.count(next))
		{
			table[next] = num + 1;
			pq.push({ -table[next], next });
		}
		next = idx * 10 + 1;
		if (next <= B && !table.count(next))
		{
			table[next] = num + 1;
			pq.push({ -table[next], next });
		}
	}
	table.count(B) ? COUT(table[B]) : COUT(-1);

	return 0;
}