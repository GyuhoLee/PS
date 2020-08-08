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
	
	string str, str2;
	cin >> str >> str2;
	int arr[26], arr2[26];
	memset(arr, 0, sizeof(arr));
	memset(arr2, 0, sizeof(arr2));
	for (auto s : str) arr[s - 'a']++;
	for (auto s : str2) arr2[s - 'a']++;
	int answer = 0;
	for (int i = 0; i < 26; i++) answer += abs(arr[i] - arr2[i]);
	cout << answer;

	return 0;
}