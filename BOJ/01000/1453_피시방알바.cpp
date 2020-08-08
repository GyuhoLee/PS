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
#include <stdlib.h>
#include <sstream>
using namespace std;

int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N;
	cin >> N;
	bool visited[101];
	memset(visited, false, sizeof(visited));
	int answer = 0;
	while (N--)
	{
		int temp;
		cin >> temp;
		if (visited[temp]) answer++;
		visited[temp] = true;
	}
	cout << answer;

	return 0;
}