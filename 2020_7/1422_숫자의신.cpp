#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define CIN(a) cin >> a;
#define CIN2(a, b) cin >> a >> b
#define CIN3(a, b, c) cin >> a >> b >> c
#define COUT(a) cout << a
#define COUT2(a, b) cout << a << ' ' << b
#define COUT3(a, b, c) cout << a << ' ' << b << ' ' << c
#define ENDL cout << '\n'
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int K, N;
int arr[1000];
int max_num = 0;
string str[1000];

bool compare(string s1, string s2)
{
	return s1 + s2 > s2 + s1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(K, N);
	FUP(i, 0, K - 1)
	{
		CIN(arr[i]);
		if (max_num < arr[i]) max_num = arr[i];
		str[i] = to_string(arr[i]);
	}
	sort(str, str + K, compare);
	bool ok = false;
	FUP(i, 0, K - 1)
	{
		if (stoi(str[i]) == max_num && !ok)
		{
			FUP(j, 1, N - K + 1) COUT(str[i]);
			ok = true;
		}
		else
		{
			COUT(str[i]);
		}
	}

	return 0;
}