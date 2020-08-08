#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <sstream>
using namespace std;

set<string> s;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
char arr[5][5];

void solve(int y, int x, string str, char ch)
{
	if (ch != 'z')
	{
		solve(y, x, str + ch, 'z');
		return;
	}
	if (str.size() == 6)
	{
		s.insert(str);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5) continue;
		solve(ny, nx, str + arr[ny][nx], 'z');
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 5; i++) 
		for (int j = 0; j < 5; j++) 
			cin >> arr[i][j];
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			solve(i, j, "", arr[i][j]);
		}
	}
	cout << s.size();

	return 0;
}