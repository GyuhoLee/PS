#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N, K;
int arr[2001];
bool visited[2002][2002];
int num[10] = { 0b1110111, 0b0010010, 0b1011101, 0b1011011, 0b0111010, 0b1101011, 0b1101111, 0b1010010, 0b1111111, 0b1111011 };
vector<pair<int, int>> v[2001];
bool found = false;
int answer[2001];

void solve(int idx, int k)
{
	if (found || visited[idx][k]) return;
	visited[idx][k] = true;
	if (idx == N + 1)
	{
		if (k == 0)
		{
			found = true;
			FUP(i, 1, N) cout << answer[i];
		}
		return;
	}
	for (auto s : v[idx])
	{
		if (k < s.second) continue;
		answer[idx] = s.first;
		solve(idx + 1, k - s.second);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	MS(visited, false);
	cin >> N >> K;
	FUP(i, 1, N)
	{
		string str;
		cin >> str;
		int gop = 1;
		int temp = 0;
		FDOWN(j, 6, 0)
		{
			if (str[j] == '1') temp += gop;
			gop *= 2;
		}
		arr[i] = temp;
		FDOWN(j, 9, 0)
		{
			int a = arr[i];
			int b = num[j];
			int cnt = 0;
			bool ok = true;
			while (a > 0 || b > 0)
			{
				if (a % 2 == 1 && b % 2 == 0)
				{
					ok = false;
					break;
				}
				if (a % 2 == 0 && b % 2 == 1) cnt++;
				a /= 2;
				b /= 2;
			}
			if (ok) v[i].push_back({ j, cnt });
		}
	}

	solve(1, K);
	if (!found) cout << -1;

	return 0;
}