#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define F(i, a, b) for(int i = a; i < b; i++)
#define MS(a, b) memset(a, b, sizeof(a))

int N, M;
int arr[1000000];
int answer = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	F(i, 0, N) cin >> arr[i];
	sort(arr, arr + N);
	int low = 0;
	int high = 2000000000;
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		int cnt = 0;
		for (int i = N - 1; i >= 0; i--)
		{
			if (arr[i] - mid <= 0) break;
			cnt += (arr[i] - mid);
		}
		if (cnt < M) high = mid - 1;
		else
		{
			low = mid + 1;
			answer = mid;
		}
	}
	cout << answer;

	return 0;
}