#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[1000000];
int B, C;
long long int answer = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	cin >> B >> C;
	for (int i = 0; i < N; i++)
	{
		answer++;
		if (A[i] <= B) continue;
		else
		{
			A[i] -= B;
			answer = answer + (A[i] / C);
			if (A[i] % C != 0) answer++;
		}
	}
	cout << answer;

	return 0;
}