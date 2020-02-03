#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string A, B;
int answer = 0;

void solve()
{
	for (int i = 0; i <= B.length() - A.length(); i++)
	{
		int temp = 0;
		for (int j = 0; j < A.length(); j++)
		{
			if (A[j] != B[j + i]) temp++;
		}
		answer = min(temp, answer);
	}
	cout << answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> A >> B;
	answer = A.length();
	solve();

	return 0;
}