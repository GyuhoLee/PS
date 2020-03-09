#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int A, B;
	cin >> A >> B;
	int answer = 0;
	int first = 0;
	for (int i = 100; i >= 1; i--)
	{
		int num = i * i;
		if (num < A) break;
		if (num > B) continue;
		answer += num;
		first = num;
	}
	if (!answer) cout << -1;
	else cout << answer << '\n' << first;

	return 0;
}