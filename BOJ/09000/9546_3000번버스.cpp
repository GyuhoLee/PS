#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int answer[31];
	answer[1] = 1;
	for (int i = 2; i <= 30; i++) answer[i] = answer[i - 1] * 2 + 1;
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		cout << answer[N] << '\n';
	}
	

	return 0;
}