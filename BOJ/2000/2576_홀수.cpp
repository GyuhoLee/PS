#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int first = 1000;
	int answer = 0;
	for (int i = 0; i < 7; i++)
	{
		int temp;
		cin >> temp;
		if (temp % 2)
		{
			first = min(first, temp);
			answer += temp;
		}
	}
	if (!answer) cout << -1;
	else cout << answer << '\n' << first;


	return 0;
}