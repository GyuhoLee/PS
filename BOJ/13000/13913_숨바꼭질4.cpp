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

int N, K, arr[100001], ans = INT_MAX;
int before[1000001];
priority_queue<pair<int, int>> pq;

void Print(int idx)
{
	if (idx != N)
	{
		Print(before[idx]);
	}
	COUT2(idx, "");
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	fill(arr, arr + 100001, INT_MAX);
	CIN2(N, K);
	FUP(i, 1, N) before[i] = i;
	arr[N] = 0;
	pq.push({ 0, N });
	while (!pq.empty())
	{
		int d = -pq.top().first;
		int num = pq.top().second;
		pq.pop();
		if (num == K)
		{
			ans = min(ans, d);
			break;
		}

		if (num != 100000 && arr[num + 1] > d + 1)
		{
			arr[num + 1] = d + 1;
			before[num + 1] = num;
			pq.push({ -arr[num + 1], num + 1 });
		}
		if (num != 0 && arr[num - 1] > d + 1)
		{
			before[num - 1] = num;
			arr[num - 1] = d + 1;
			pq.push({ -arr[num - 1], num - 1 });
		}
		if (num * 2 <= 100000 && arr[num * 2] > d + 1)
		{
			before[num * 2] = num;
			arr[num * 2] = d + 1;
			pq.push({ -arr[num * 2], num * 2 });
		}
	}
	COUT(ans);
	ENDL;
	Print(K);


	return 0;
}