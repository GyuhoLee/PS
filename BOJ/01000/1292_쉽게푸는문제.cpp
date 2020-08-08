#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int arr[1001];
	int num = 1;
	int cnt = 0;
	for (int i = 1; i <= 1000; i++)
	{
		arr[i] = num;
		cnt++;
		if (cnt == num)
		{
			num++;
			cnt = 0;
		}
	}
	int A, B;
	cin >> A >> B;
	int answer = 0;
	for (int i = A; i <= B; i++) answer += arr[i];
	cout << answer;

	return 0;
}