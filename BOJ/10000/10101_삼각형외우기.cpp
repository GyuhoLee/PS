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

	int arr[3];
	int total = 0;
	FUP(i, 0, 2)
	{
		cin >> arr[i];
		total += arr[i];
	}
	string str;
	sort(arr, arr + 3);
	if (total != 180) str = "Error";
	else if (arr[0] == arr[1] && arr[1] == arr[2]) str = "Equilateral";
	else if (arr[0] == arr[1] || arr[1] == arr[2]) str = "Isosceles";
	else str = "Scalene";
	cout << str;



	return 0;
}