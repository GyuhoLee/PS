#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	int answer = 1;
	while (N--)
	{
		int temp;
		cin >> temp;
		answer += temp - 1;
	}
	cout << answer;

	return 0;
}