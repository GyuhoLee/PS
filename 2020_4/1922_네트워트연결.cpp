#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N, M;
int a, b, c;
int parent[100001];
int line = 0;
int answer = 0;
vector<pair<int, pair<int, int>>> arr;

int find_parent(int num)
{
	if (num == parent[num]) return num;
	else return parent[num] = find_parent(parent[num]);
}

void Merge(int x, int y)
{
	x = find_parent(x);
	y = find_parent(y);

	if (x != y)
	{
		if (x < y) parent[y] = x;
		else parent[x] = y;
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	FUP(i, 1, N) parent[i] = i;
	FUP(i, 0, M - 1)
	{
		cin >> a >> b >> c;
		if (a == b) continue;
		arr.push_back({ c, {a, b} });
	}
	sort(ALL(arr));
	FUP(i, 0, arr.size() - 1)
	{
		a = arr[i].second.first;
		b = arr[i].second.second;
		if (find_parent(a) == find_parent(b)) continue;
		Merge(a, b);
		answer += arr[i].first;
		line++;
		if (line == N - 1) break;
	}
	cout << answer;

	return 0;
}