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

int N;
pair<string, int> arr[1000];

bool compare(pair<string, int>& A, pair<string, int>& B)
{
	if (A.first.length() == B.first.length())
	{
		if (A.second == B.second)
		{
			return A.first < B.first;
		}
		return A.second < B.second;
	}
	return A.first.length() < B.first.length();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	FUP(i, 0, N - 1)
	{
		CIN(arr[i].first);
		arr[i].second = 0;
		for (char ch : arr[i].first)
		{
			if (ch >= '0' && ch <= '9')
			{
				arr[i].second += (ch - '0');
			}
		}
	}
	sort(arr, arr + N, compare);
	FUP(i, 0, N - 1)
	{
		COUT(arr[i].first);
		ENDL;
	}

	return 0;
}