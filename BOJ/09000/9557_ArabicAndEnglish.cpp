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
	
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		string arr[100];
		int temp = -1;
		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
			if (arr[i][0] != '#') temp = i;
		}
		if (temp != -1)
		{
			for (int i = temp + 1; i < N; i++) cout << arr[i] << ' ';
			cout << arr[temp] << ' ';
			for (int i = 0; i < temp; i++) cout << arr[i] << ' ';
		}
		else
		{
			for (int i = 0; i < N; i++) cout << arr[i] << ' ';
		}

		cout << '\n';
	}

	return 0;
}