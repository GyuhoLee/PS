#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		int num;
		int arr[10] = { 0, };
		cin >> num;
		while (num > 0)
		{
			arr[num % 10]++;
			num /= 10;
		}
		int answer = 0;
		for (int i = 0; i < 10; i++)
			if (arr[i]) answer++;
		cout << answer << '\n';
	}

	return 0;
}