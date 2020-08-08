#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define ENDL '\n'
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int arr1[6] = { 1, 2, 3, 3, 4, 10 };
	int arr2[7] = { 1, 2, 2, 2, 3, 5 ,10 };
	int T;
	cin >> T;
	FUP(tc, 1, T)
	{
		int num1 = 0, num2 = 0;
		FUP(i, 0, 5)
		{
			int temp;
			cin >> temp;
			num1 += (arr1[i] * temp);
		}
		FUP(i, 0, 6)
		{
			int temp;
			cin >> temp;
			num2 += (arr2[i] * temp);
		}
		cout << "Battle " << tc << ": ";
		if (num1 > num2) cout << "Good triumphs over Evil\n";
		else if (num1 < num2) cout << "Evil eradicates all trace of Good\n";
		else cout << "No victor on this battle field\n";
	}

	return 0;
}