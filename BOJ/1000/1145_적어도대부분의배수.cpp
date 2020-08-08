#include <bits/stdc++.h>
using namespace std;

int A, B;
int answer = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int arr[5];
	for (int i = 0; i < 5; i++) cin >> arr[i];
	int i = 1;
	while (1)
	{
		int cnt = 0;
		for (int j = 0; j < 5; j++)
		{
			if (i % arr[j] == 0) cnt++;
		}
		if (cnt >= 3) break;
		i++;
	}
	cout << i;

	return 0;
}