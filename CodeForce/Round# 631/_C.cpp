#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define F(i, a, b) for(int i = a; i <= b; i++)
#define MS(a, b) memset(a, b, sizeof(a))

int N, M;
ll arr[100001];
int answer[100001];
ll total = 0;
bool ok = true;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(answer, 0);
	cin >> N >> M;
	F(i, 1, M)
	{
		cin >> arr[i];
		if (N - arr[i] < i - 1) ok = false;
		total += arr[i];
	}
	if (total < N || !ok)
	{
		cout << -1;
		return 0;
	}
	int stay = N;
	F(i, 1, M)
	{
		if (total - arr[i] < stay - 1)
		{
			int beforeStay = stay;
			stay = total - arr[i];
			answer[i] = beforeStay - arr[i] + 1;
		}
		else
		{
			answer[i] = stay - arr[i] + 1;
			stay--;
		}
		total -= arr[i];
	}
	
	F(i, 1, M)
	{
		cout << answer[i] << ' ';
	}

	return 0;
}