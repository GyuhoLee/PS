#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll N, C;
ll arr[250001];
ll leftD[250001];
ll rightD[250001];
pair<int, ll> answer = { -1, LONG_MAX };


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> C;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	leftD[1] = 0;
	for (int i = 2; i <= N; i++)
	{
		ll temp;
		if (arr[i] < arr[i - 1]) temp = arr[i - 1] - arr[i];
		else if (arr[i] == arr[i - 1]) temp = 0;
		else temp = C - arr[i] + arr[i - 1];
		leftD[i] = leftD[i - 1] + temp;
	}
	rightD[N] = 0;
	for (int i = N - 1; i >= 1; i--)
	{
		ll temp;
		if (arr[i] < arr[i + 1]) temp = arr[i + 1] - arr[i];
		else if (arr[i] == arr[i + 1]) temp = 0;
		else temp = C - arr[i] + arr[i + 1];
		rightD[i] = rightD[i + 1] + temp;
	}
	for (int i = 1; i <= N; i++)
	{
		if (max(leftD[i], rightD[i]) < answer.second)
		{
			answer = { i, max(leftD[i], rightD[i]) };
		}
	}
	cout << answer.first << '\n' << answer.second;

	return 0;
}