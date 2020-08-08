#include <bits/stdc++.h>
using namespace std;

int A, B;
int answer = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N >> A >> B;
	while (A != B)
	{
		A = (A + 1) / 2;
		B = (B + 1) / 2;
		answer++;
	}
	cout << answer;

	return 0;
}