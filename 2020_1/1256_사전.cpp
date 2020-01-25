#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int N, M, K;
string answer;
int cnt = 0;
bool found = false;

void solve(string str, int a, int z)
{
	if (found) return;
	if (!a && !z)
	{
		if (cnt == K - 1)
		{
			answer = str;
			found = true;
		}
		cnt++;
	}
	else if (a && z)
	{
		solve(str + 'a', a - 1, z);
		solve(str + 'z', a, z - 1);
	}
	else if (!a)
	{
		solve(str + 'z', a, z - 1);
	}
	else if (!z)
	{
		solve(str + 'a', a - 1, z);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	solve("", N, M);
	if (cnt < K) answer = "-1";
	cout << answer;

	return 0;
}