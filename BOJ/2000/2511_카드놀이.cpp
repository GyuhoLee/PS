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
	
	int A[10];
	int B[10];
	int a = 0;
	int b = 0;
	int AW = 0;
	int BW = 0;

	FUP(i, 0, 9)
	{
		cin >> A[i];
	}
	FUP(i, 0, 9)
	{
		cin >> B[i];
	}
	FUP(i, 0, 9)
	{
		if (A[i] > B[i])
		{
			AW = i;
			a += 3;
		}
		else if (B[i] > A[i])
		{
			BW = i;
			b += 3;
		}
		else
		{
			a++;
			b++;
		}
	}

	cout << a << ' ' << b << '\n';
	if (a > b)
	{
		cout << "A";
	}
	else if (b > a)
	{
		cout << "B";
	}
	else
	{
		if (AW > BW) cout << "A";
		else if (AW < BW) cout << "B";
		else cout << "D";
	}

	return 0;
}