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

int cnt[10];
string str;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	CIN(T);
	while (T--)
	{
		MS(cnt, 0);
		CIN(str);
		int L = str.length();
		for (char ch : str)
		{
			cnt[ch - '0']++;
		}
		int answer = 0;
		FUP(i, 0, 9) answer = max(answer, cnt[i]);
		FUP(i, 0, 9)
		{
			FUP(j, 0, 9)
			{
				int temp_cnt = 0;
				bool state = true;
				for (char ch : str)
				{
					if (state)
					{
						if (ch - '0' == i)
						{
							temp_cnt++;
							state = !state;
						}
					}
					else
					{
						if (ch - '0' == j)
						{
							temp_cnt++;
							state = !state;
						}
					}
				}
				if (temp_cnt % 2 == 1) temp_cnt--;
				answer = max(temp_cnt, answer);
			}
		}
		COUT(L - answer);
		ENDL;

	}

	return 0;
}