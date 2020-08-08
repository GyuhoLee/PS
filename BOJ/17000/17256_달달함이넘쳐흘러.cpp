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
	
	int a_x, a_y, a_z;
	int c_x, c_y, c_z;
	cin >> a_x >> a_y >> a_z;
	cin >> c_x >> c_y >> c_z;
	cout << c_x - a_z << ' ' << c_y / a_y << ' ' << c_z - a_x;

	return 0;
}