#include <bits/stdc++.h>
using namespace std;

int input[200000];
bool arr[200001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		int cnt = 0;
		bool cont = false;
		memset(arr, false, sizeof(arr));
		int N;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> input[i];
			if (!arr[input[i]])
			{
				arr[input[i]] = true;
				cnt++;
			}
			if (i && input[i] == input[i - 1]) cont = true;
		}
		if (input[N - 1] == input[0]) cont = true;
		if (cnt == 1)
		{
			cout << "1\n";
			for (int i = 0; i < N; i++) cout << "1 ";
			cout << '\n';
			continue;
		}
		if (N % 2 == 0)
		{
			cout << "2\n";
			for (int i = 0; i < N / 2; i++) cout << "1 2 ";
			cout << '\n';
			continue;
		}
		if (cont)
		{
			bool ok = false;
			cout << "2\n";
			cout << "1 ";
			int num[2] = { 1, 2 };
			int idx = 1;
			for (int i = 1; i < N; i++)
			{
				if (!ok && input[i] == input[i - 1])
				{
					idx = (idx + 1) % 2;
					ok = true;
				}
				cout << num[idx] << ' ';
				idx = (idx + 1) % 2;
			}
			cout << '\n';
			continue;
		}
		int num[2] = { 1, 2 };
		cout << "3\n";
		for (int i = 0; i < N - 1; i++)
		{
			cout << num[i % 2] << ' ';
		}
		cout << "3\n";
		
	}

	return 0;
}