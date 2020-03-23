#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll arr[200000];
ll answer[200000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	int before;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	answer[0] = arr[0];
	before = answer[0];
	cout << answer[0] << ' ';
	for (int i = 1; i < N; i++)
	{
		answer[i] = arr[i] + before;
		if (answer[i] > before) before = answer[i];
		else if (answer[i] < 0) answer[i] = 0;
		cout << answer[i] << ' ';
	}

	return 0;
}