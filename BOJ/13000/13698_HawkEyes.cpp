#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define CIN1(a) cin >> a;
#define CIN2(a, b) cin >> a >> b
#define CIN3(a, b, c) cin >> a >> b >> c
#define COUT1(a) cout << a
#define COUT2(a, b) cout << a << ' ' << b
#define COUT3(a, b, c) cout << a << ' ' << b << ' ' << c
#define ENDL cout << '\n'
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int arr[4] = { 1, 0, 0, 2 };
	string str;
	CIN1(str);
	for (char ch : str)
	{
		switch (ch)
		{
		case 'A':
			swap(arr[0], arr[1]);
			break;
		case 'B':
			swap(arr[0], arr[2]);
			break;
		case 'C':
			swap(arr[0], arr[3]);
			break;
		case 'D':
			swap(arr[1], arr[2]);
			break;
		case 'E':
			swap(arr[1], arr[3]);
			break;
		case 'F':
			swap(arr[2], arr[3]);
			break;
		}
	}
	FUP(i, 0, 3)
	{
		if (arr[i] == 1)
		{
			COUT1(i + 1);
			ENDL;
		}
	}
	FUP(i, 0, 3)
	{
		if (arr[i] == 2)
		{
			COUT1(i + 1);
		}
	}

    return 0;


}