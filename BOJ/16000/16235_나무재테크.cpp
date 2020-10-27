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
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int N, M, K, A[11][11], arr[11][11], x, y, z;
vector<int> tree[11][11];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN3(N, M, K);
	FUP(i, 1, N)
	{
		FUP(j, 1, N)
		{
			CIN(A[i][j]);
			arr[i][j] = 5;
		}
	}
	while (M--)
	{
		CIN3(x, y, z);
		tree[x][y].push_back(z);
	}

	FUP(year, 1, K)
	{
		FUP(i, 1, N)
		{
			FUP(j, 1, N)
			{
				sort(ALL(tree[i][j]));
				int k;
				for (k = 0; k < tree[i][j].size(); k++)
				{
					if (arr[i][j] < tree[i][j][k]) break;
					arr[i][j] -= tree[i][j][k]++;
				}
				for (int l = tree[i][j].size() - 1; l >= k; l--)
				{
					arr[i][j] += (tree[i][j][l] / 2);
					tree[i][j].pop_back();
				}
			}
		}
		FUP(i, 1, N)
		{
			FUP(j, 1, N)
			{
				for(int num : tree[i][j])
				{
					if (num % 5 == 0)
					{
						FUP(k, 0, 7)
						{
							int nx = i + dx[k];
							int ny = j + dy[k];
							if (ny <= 0 || nx <= 0 || ny > N || nx > N) continue;
							tree[nx][ny].push_back(1);
						}
					}
				}
				arr[i][j] += A[i][j];
			}
		}
	}
	int ans = 0;
	FUP(i, 1, N)
	{
		FUP(j, 1, N)
		{
			ans += tree[i][j].size();
		}
	}
	COUT(ans);

	return 0;
}