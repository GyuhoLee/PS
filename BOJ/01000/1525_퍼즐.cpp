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

string str = "";
map<string, int> cnt;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	FUP(i, 1, 9)
	{
		string tmp;
		CIN(tmp);
		str += tmp;
	}
	cnt[str] = 0;
	queue<string> q;
	q.push(str);
	while (!q.empty())
	{
		str = q.front();
		if (str == "123456780") break;
		q.pop();
		int idx = str.find('0');
		int y = idx / 3;
		int x = idx % 3;
		FUP(i, 0, 3)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny > 2 || nx > 2) continue;
			string tmp = str;
			swap(tmp[idx], tmp[ny * 3 + nx]);
			if (!cnt.count(tmp))
			{
				cnt[tmp] = cnt[str] + 1;
				q.push(tmp);
			}
		}
	}
	cnt.count("123456780") ? COUT(cnt["123456780"]) : COUT("-1");



	return 0;
}