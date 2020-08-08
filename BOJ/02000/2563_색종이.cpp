#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <string>
#include <string.h>
#include <limits.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int visited[111][111];
	memset(visited, 0, sizeof(visited));
	int N;
	cin >> N;
	while (N--)
	{
		int a, b;
		cin >> a >> b;
		for (int i = a; i < a + 10; i++)
		{
			for (int j = b; j < b + 10; j++)
			{
				visited[i][j] = 1;
			}
		}
	}
	int answer = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			answer += visited[i][j];
		}
	}
	cout << answer;

	return 0;
}