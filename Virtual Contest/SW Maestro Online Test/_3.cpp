#include <bits/stdc++.h>
using namespace std;

int N, K;
int arr[3000];
int temp[3000];
int answer;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> arr[i];
	answer = arr[N - 1] - arr[0];
	for (int i = 0; i < N - 1; i++) temp[i] = arr[i + 1] - arr[i];
	sort(temp, temp + N - 1, greater<int>());
	for (int i = 0; i < K - 1; i++) answer -= temp[i];
	cout << answer;


	return 0;
}