#include <bits/stdc++.h>
using namespace std;

int A[200000];
int B[200000];
int arr[200000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long int answer = 0;
	long long int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) cin >> B[i];
	for (int i = 0; i < N; i++) arr[i] = A[i] - B[i];
	sort(arr, arr + N);
	long long int x = 0;
	for (int i = 0; i < N; i++)
	{
		x = i;
		if (arr[i] > 0) break;
	}
	answer += ((N - x) * (N - x - 1) / 2);
	long long int y = N - 1;
	for (int i = 0; i < x; i++)
	{
		while (arr[y] + arr[i] > 0)
		{
			y--;
		}
		answer += (N - y - 1);
	}
	cout << answer;


	return 0;
}