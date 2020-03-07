#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int arr[30];
	memset(arr, 0, sizeof(arr));
	int N;
	cin >> N;
	while (N--)
	{
		int num;
		cin >> num;
		int i = 0;
		while (num > 0)
		{
			if (num % 2 == 1) arr[i]++;
			num /= 2;
			i++;
		}
	}
	int answer = 0;
	int j = 1;
	for (int i = 0; i < 30; i++)
	{
		if (arr[i] % 2 == 1)
		{
			answer += j;
		}
		j *= 2;
	}
	cout << answer;
}