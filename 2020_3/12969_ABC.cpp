#include <bits/stdc++.h>
using namespace std;

int N, K;
bool visited[31][31][31][436];
bool found = false;

void solve(int x, int a, int b, int cnt, string str)
{
	if (found) return;
	if (visited[x][a][b][cnt]) return;
	visited[x][a][b][cnt] = true;
	if (x == N)
	{
		if (cnt == K)
		{
			cout << str;
			found = true;
		}
		return;
	}
	solve(x + 1, a + 1, b, cnt, str + 'A');
	solve(x + 1, a, b + 1, cnt + a, str + 'B');
	solve(x + 1, a, b, cnt + a + b, str + 'C');
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	solve(0, 0, 0, 0, "");
	if (!found) cout << -1;

	return 0;
}