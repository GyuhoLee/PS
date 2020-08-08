#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

vector<int> v;

void DFS(int num)
{
	if (num > 1000000) return;
	v.push_back(num);
	DFS(num * 10 + 4);
	DFS(num * 10 + 7);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	DFS(4);
	DFS(7);
	sort(ALL(v));
	int N;
	cin >> N;
	auto iter = upper_bound(ALL(v), N);
	iter--;
	cout << *iter;

	return 0;
}