#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

map<int, int> Map;
int N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	while (N--)
	{
		int temp;
		cin >> temp;
		if (!Map.count(temp)) Map[temp] = 1;
		else Map[temp] = Map[temp] + 1;
	}
	cin >> M;
	while (M--)
	{
		int temp;
		cin >> temp;
		if (Map.count(temp)) cout << Map[temp] << ' ';
		else cout << "0 ";
	}

	return 0;
}