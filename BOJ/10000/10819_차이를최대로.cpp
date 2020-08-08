#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N;
int arr[8];
int seq[8];
int seq2[8];
int answer = 0, answer2 = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	FUP(i, 0, N - 1) cin >> arr[i];
	sort(arr, arr + N);
	int Left = 0, Right = N - 1, idx = 0;
	while (Left <= Right)
	{
		if (Left == Right)
		{
			seq[idx] = Left;
			seq2[idx] = Left;
		}
		else
		{
			seq[idx] = Left;
			seq2[idx] = Right;
			idx++;
			seq[idx] = Right;
			seq2[idx] = Left;
			idx++;
		}
		Left++;
		Right--;
	}
	FUP(i, 0, N - 3)
	{
		answer += abs(arr[seq[i + 1]] - arr[seq[i]]);
		answer2 += abs(arr[seq2[i + 1]] - arr[seq2[i]]);
	}
	answer += abs(arr[seq[N - 1]] - arr[seq[0]]);
	answer2 += abs(arr[seq2[N - 1]] - arr[seq2[0]]);
	cout << max(answer, answer2);

	return 0;
}