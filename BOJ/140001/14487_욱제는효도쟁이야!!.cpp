#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	int maxNum = -1;
	int answer = 0;
	while (N--)
	{
		int temp;
		cin >> temp;
		answer += temp;
		if (temp > maxNum) maxNum = temp;
	}
	cout << answer - maxNum;
	

	return 0;
}