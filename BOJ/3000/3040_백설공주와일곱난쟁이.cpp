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
	
	int arr[9];
	bool ok[9];
	int total = 0;
	FUP(i, 0, 8)
	{
		cin >> arr[i];
		total += arr[i];
		ok[i] = true;
	}
	int num = total - 100;
	FUP(i, 0, 7)
	{
		FUP(j, i + 1, 8)
		{
			if (arr[i] + arr[j] == num)
			{
				ok[i] = false;
				ok[j] = false;
				break;
			}
		}
		if (!ok[i]) break;
	}
	FUP(i, 0, 8)
	{
		if (ok[i]) cout << arr[i] << '\n';
	}

	return 0;
}