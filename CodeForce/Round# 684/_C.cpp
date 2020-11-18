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

int T, N, M;
char arr[101][101];
vector<int> tmp(6);

void change(int i, int j)
{
	if (arr[i][j] == '0') arr[i][j] = '1';
	else arr[i][j] = '0';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(T);
	while (T--)
	{
		int ans = 0;
		vector<vector<int>> v;
		CIN2(N, M);
		FUP(i, 1, N)
		{
			FUP(j, 1, M)
			{
				CIN(arr[i][j]);
			}
		}
		FUP(i, 1, N)
		{
			FUP(j, 1, M)
			{
				if (arr[i][j] == '0') continue;
				if (j == M)
				{
					if (i == N)
					{
						tmp[0] = i - 1; tmp[1] = j - 1;
						tmp[2] = i - 1; tmp[3] = j;
						tmp[4] = i; tmp[5] = j;
						v.push_back(tmp);
						tmp[0] = i - 1; tmp[1] = j - 1;
						tmp[2] = i; tmp[3] = j - 1;
						tmp[4] = i; tmp[5] = j;
						v.push_back(tmp);
						tmp[0] = i - 1; tmp[1] = j;
						tmp[2] = i; tmp[3] = j - 1;
						tmp[4] = i; tmp[5] = j;
						v.push_back(tmp);
					}
					else
					{
						change(i, j);
						change(i + 1, j);
						change(i + 1, j - 1);
						tmp[0] = i; tmp[1] = j;
						tmp[2] = i + 1; tmp[3] = j - 1;
						tmp[4] = i + 1; tmp[5] = j;
						v.push_back(tmp);
					}
					
				}
				else
				{
					if (i == N)
					{
						change(i, j);
						change(i, j + 1);
						tmp[0] = i - 1; tmp[1] = j;
						tmp[2] = i - 1; tmp[3] = j + 1;
						tmp[4] = i; tmp[5] = j;
						v.push_back(tmp);
						tmp[4] = i; tmp[5] = j + 1;
						v.push_back(tmp);
					}
					else
					{
						change(i, j);
						change(i, j + 1);
						change(i + 1, j);
						tmp[0] = i; tmp[1] = j;
						tmp[2] = i; tmp[3] = j + 1;
						tmp[4] = i + 1; tmp[5] = j;
						v.push_back(tmp);
					}
				}
			}
		}
		COUT(v.size());
		ENDL;
		for (auto vv : v)
		{
			cout << vv[0] << ' ' << vv[1] << ' ' << vv[2] << ' ' << vv[3] << ' ' << vv[4] << ' ' << vv[5] << '\n';
		}

	}

	return 0;
}