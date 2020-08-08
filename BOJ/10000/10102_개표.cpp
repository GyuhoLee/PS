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
	
	int A = 0, B = 0, V;
	
	cin >> V;
	while (V--)
	{
		char temp;
		cin >> temp;
		if (temp == 'A') A++;
		else B++;
	}
	if (A == B) cout << "Tie";
	else A > B ? cout << "A" : cout << "B";


	return 0;
}