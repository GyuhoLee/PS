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
	
	int arr[101];
	int answer[101];
	int N;
	cin >> N;
	int sum = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		int temp = arr[i] * i;
		answer[i] = temp - sum;
		sum = temp;
	}
	for (int i = 1; i <= N; i++) cout << answer[i] << ' ';


	return 0;
}