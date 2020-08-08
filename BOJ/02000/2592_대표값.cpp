#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int arr[1000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int idx = 0;
	int num = 0;
	MS(arr, 0);
	int total = 0;
	FUP(i, 1, 10)
	{
		int temp;
		cin >> temp;
		total += temp;
		arr[temp]++;
		if (arr[temp] > num)
		{
			num = arr[temp];
			idx = temp;
		}
	}
	cout << total / 10 << '\n' << idx;
	

	return 0;
}