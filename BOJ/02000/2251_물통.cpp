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

int A, B, C, a, b, c;
bool visited[201][201][201];
set<int> answer;

struct Water
{
	int a, b, c;
	Water(int aa, int bb, int cc) : a(aa), b(bb), c(cc) {}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(visited, false);
	CIN3(A, B, C);
	visited[0][0][C] = true;

	queue<Water> q;
	q.push(Water(0, 0, C));
	while (!q.empty())
	{
		Water water = q.front();
		q.pop();
		if (water.a == 0)
		{
			answer.insert(water.c);
		}
		else
		{
			if (water.a + water.b > B)
			{
				a = water.a + water.b - B;
				b = B;
				c = water.c;
			}
			else
			{
				a = 0;
				b = water.a + water.b;
				c = water.c;
			}
			if (!visited[a][b][c])
			{
				q.push(Water(a, b, c));
				visited[a][b][c] = true;
			}

			if (water.a + water.c > C)
			{
				a = water.a + water.c - C;
				b = water.b;
				c = C;
			}
			else
			{
				a = 0;
				b = water.b;
				c = water.a + water.c;
			}
			if (!visited[a][b][c])
			{
				q.push(Water(a, b, c));
				visited[a][b][c] = true;
			}
		}
		if (water.b != 0)
		{
			if (water.a + water.b > A)
			{
				a = A;
				b = water.a + water.b - A;
				c = water.c;
			}
			else
			{
				a = water.a + water.b;
				b = 0;
				c = water.c;
			}
			if (!visited[a][b][c])
			{
				q.push(Water(a, b, c));
				visited[a][b][c] = true;
			}

			if (water.b + water.c > C)
			{
				a = water.a;
				b = water.b + water.c - C;
				c = C;
			}
			else
			{
				a = water.a;
				b = 0;
				c = water.b + water.c;
			}
			if (!visited[a][b][c])
			{
				q.push(Water(a, b, c));
				visited[a][b][c] = true;
			}
		}
		if (water.c != 0)
		{
			if (water.a + water.c > A)
			{
				a = A;
				b = water.b;
				c = water.a + water.c - A;
			}
			else
			{
				a = water.a + water.c;
				b = water.b;
				c = 0;
			}
			if (!visited[a][b][c])
			{
				q.push(Water(a, b, c));
				visited[a][b][c] = true;
			}
			if (water.b + water.c > B)
			{
				a = water.a;
				b = B;
				c = water.b + water.c - B;
			}
			else
			{
				a = water.a;
				b = water.b + water.c;
				c = 0;
			}
			if (!visited[a][b][c])
			{
				q.push(Water(a, b, c));
				visited[a][b][c] = true;
			}
		}
	}

	for (int num : answer)
	{
		COUT2(num, "");
	}

	return 0;
}