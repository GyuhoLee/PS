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
	cin >> arr[0] >> arr[1] >> arr[2];
	sort(arr, arr + 3);
	int num1 = arr[1] - arr[0];
	int num2 = arr[2] - arr[1];
	if (num1 == num2)
	{
		cout << arr[2] + num1;
	}
	else if (num1 > num2)
	{
		cout << arr[0] + num2;
	}
	else
	{
		cout << arr[1] + num1;
	}

	return 0;
}