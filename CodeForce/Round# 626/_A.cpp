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
		int arr[101];
		int N;
		cin >> N;
		int answer = 0;
		for (int i = 1; i <= N; i++)
		{
			cin >> arr[i];
			if (arr[i] % 2 == 0) answer = i;
		}
		if (answer)
		{
			cout << "1\n" << answer << "\n";
		}
		else
		{
			if (N < 2) cout << "-1\n";
			else cout << "2\n1 2\n";
		}

	}

	return 0;
}