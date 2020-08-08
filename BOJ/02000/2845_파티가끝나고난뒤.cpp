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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N, M;
	cin >> N >> M;
	int answer = N * M;
	for (int i = 0; i < 5; i++)
	{
		int temp;
		cin >> temp;
		cout << temp - answer << ' ';
	}

	return 0;
}