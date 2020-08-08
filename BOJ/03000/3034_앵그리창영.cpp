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
	
	int N, R, C;
	cin >> N >> R >> C;
	int num = R * R + C * C;
	while (N--)
	{
		int temp;
		cin >> temp;
		if (temp * temp <= num) cout << "DA\n";
		else cout << "NE\n";
	}
	return 0;
}