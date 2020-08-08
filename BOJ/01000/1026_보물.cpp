#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	int A[100], B[100];
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) cin >> B[i];
	sort(A, A + N);
	sort(B, B + N, greater<int>());
	int answer = 0;
	for (int i = 0; i < N; i++) answer += (A[i] * B[i]);
	cout << answer;



	return 0;
}