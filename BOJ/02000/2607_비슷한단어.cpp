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

int N, ans = 0, arr[26], cnt[26];
string word, str;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(arr, 0);
	CIN2(N, word);
	for (char ch : word) arr[ch - 'A']++;
	N--;
	while (N--)
	{
		CIN(str);
		MS(cnt, 0);
		for (char ch : str) cnt[ch - 'A']++;
		int sum = 0, num = 0, abso = 0;
		FUP(i, 0, 25)
		{
			if (arr[i] != cnt[i])
			{
				num++;
				sum += (arr[i] - cnt[i]);
				abso += abs(arr[i] - cnt[i]);
			}
		}
		if (num == 0) ans++;
		else if (num == 1 && abso == 1) ans++;
		else if (num == 2 && sum == 0 && abso == 2) ans++;
	}
	COUT(ans);

	return 0;
}