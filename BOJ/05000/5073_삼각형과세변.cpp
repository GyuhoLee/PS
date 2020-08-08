#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (1)
	{
		string str;
		int arr[3];
		cin >> arr[0] >> arr[1] >> arr[2];
		sort(arr, arr + 3);
		if (!arr[0]) break;
		if (arr[0] + arr[1] <= arr[2]) str = "Invalid";
		else if (arr[0] == arr[1] && arr[1] == arr[2]) str = "Equilateral";
		else if (arr[0] == arr[1] || arr[1] == arr[2]) str = "Isosceles";
		else str = "Scalene";
		cout << str << '\n';
	}

	return 0;
}