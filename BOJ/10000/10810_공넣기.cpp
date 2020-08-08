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
	int arr[100] = { 0, };
	while (M--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		for (int i = a - 1; i <= b - 1; i++) arr[i] = c;

	}
	for (int i = 0; i < N; i++) cout << arr[i] << ' ';


	return 0;
}