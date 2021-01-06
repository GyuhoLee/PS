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

int N, M, D, ans = 0;
vector<vector<int>> state;
vector<int> permut;

void solve(vector<vector<int>> arr, vector<int> permut)
{
	int cnt = 0;
	set<pair<int, int>> S;
	vector<int> archer;
	FUP(i, 0, M - 1)
	{
		if (permut[i]) archer.push_back(i);
	}
	FUP(row, 0, N - 1)
	{
		for (int col : archer)
		{
			FUP(d, 0, D - 1)
			{
				bool ok = false;
				FUP(j, -d, d)
				{
					int i = d - abs(j);
					if (row + i >= N || col + j >= M || col + j < 0) continue;
					if (arr[row + i][col + j])
					{
						S.insert({ row + i, col + j });
						ok = true;
						break;
					}
				}
				if (ok) break;
			}
		}
		for (auto p : S)
		{
			arr[p.first][p.second] = 0;
			cnt++;
		}
		S.clear();
	}
	ans = max(ans, cnt);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN3(N, M, D);
	state.resize(N, vector<int>(M));
	FDOWN(i, N - 1, 0)
	{
		FUP(j, 0, M - 1)
		{
			CIN(state[i][j]);
		}
	}
	permut.resize(M, 0);
	FDOWN(i, M - 1, M - 3)
	{
		permut[i] = 1;
	}
	do
	{
		solve(state, permut);
	} while (next_permutation(ALL(permut)));
	COUT(ans);

	return 0;
}