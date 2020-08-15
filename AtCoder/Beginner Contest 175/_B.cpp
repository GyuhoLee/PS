#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(auto i = a; i <= b; i++)
#define FDOWN(i, a, b) for(auto i = a; i >= b; i--)
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
vector<pair<ll, ll>> V;
map<ll, ll> M;
ll answer = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	CIN(N);
	while (N--)
	{
		int num;
		CIN(num);
		M[num]++;
	}
	for (auto iter : M)
	{
		V.push_back({ iter.first, iter.second });
	}
	if (V.size() < 3)
	{
		COUT(0);
		return 0;
	}
	FUP(i, 0, V.size() - 3)
	{
		FUP(j, i + 1, V.size() - 2)
		{
			FUP(k, j + 1, V.size() - 1)
			{
				if (V[i].first + V[j].first > V[k].first)
				{
					answer += (V[i].second * V[j].second * V[k].second);
				}
				else break;
			}
		}
	}
	COUT(answer);

	return 0;
}