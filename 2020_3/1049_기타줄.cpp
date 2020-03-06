#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N, M;
	int A = 1000, B = 1000;
	cin >> N >> M;
	while (M--)
	{
		int a, b;
		cin >> a >> b;
		A = min(A, a);
		B = min(B, b);
	}
	if (B * 6 <= A)
	{
		cout << B * N;
		return 0;
	}
	int answer = N / 6 * A;
	int temp = N % 6;
	if (temp * B >= A) answer += A;
	else answer += (temp * B);
	cout << answer;
	

	return 0;
}
