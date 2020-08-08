#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int arr[1501];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	FUP(i, 0, 1500) arr[i] = 1;

	for(int i = 2; i <= sqrt(1500); i++)
	{
		if (arr[i] == 0) continue;
		for (int j = i + i; j <= 1500; j += i) arr[j] = 0;
	}

	int sum = 0;
	string str;
	cin >> str;
	for (char ch : str)
	{
		int num;
		if (ch >= 'a') num = ch - 'a' + 1;
		else num = ch - 'A' + 27;
		sum += num;
	}
	if (arr[sum]) cout << "It is a prime word.";
	else cout << "It is not a prime word.";

	return 0;
}