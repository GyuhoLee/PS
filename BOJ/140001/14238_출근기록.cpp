#include <bits/stdc++.h>
using namespace std;

string S;
int len;
int A = 0, B = 0, C = 0;
bool visited[51][51][51][3];
bool found = false;

void input()
{
	memset(visited, false, sizeof(visited));
	cin >> S;
	len = S.length();
	for (auto s : S)
	{
		switch (s)
		{
		case 'A': A++; break;
		case 'B': B++; break;
		case 'C': C++; break;
		}
	}
}

void solve(int a, int b, int c, string str)
{
	if (str.length() != 0)
	{
		int d;
		switch (str.back())
		{
		case 'A': d = 0; break;
		case 'B': d = 1; break;
		case 'C': d = 2; break;
		}
		if (visited[a][b][c][d]) return;
		visited[a][b][c][d] = true;
	}
	if (found) return;
	if (a + b + c == 0)
	{
		cout << str;
		found = true;
		return;
	}
	if (c && (str.length() == 0 || (str.length() == 1 && str[0] != 'C') || (str[str.length() - 1] != 'C' && str[str.length() - 2] != 'C'))) solve(a, b, c - 1, str + 'C');
	if (b && (str.length() == 0 || str.back() != 'B')) solve(a, b - 1, c, str + 'B');
	if (a) solve(a - 1, b, c, str + 'A');
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	solve(A, B, C, "");
	if (!found) cout << -1;

	return 0;
}