#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	int answer = N / 5;
	if (N % 5)answer++;
	cout << answer;
	

	return 0;
}