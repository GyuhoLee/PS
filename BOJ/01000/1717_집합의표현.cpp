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
int arr[1000001];

int parent(int num)
{
	if (num == arr[num]) return num;
	else return arr[num] = parent(arr[num]);
}

void Merge(int a, int b)
{
	while (1)
	{
		if (a == arr[a])
		{
			arr[a] = b;
			return;
		}
		int temp = arr[a];
		arr[a] = b;
		a = temp;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	FUP(i, 0, N) arr[i] = i;
	while (M--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (!a)
		{
			if (c > b) Merge(c, parent(b));
			else Merge(b, parent(c));
		}
		else
		{
			if (parent(b) == parent(c)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	int abc;
	return 0;
}