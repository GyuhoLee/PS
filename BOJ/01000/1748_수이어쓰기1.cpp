#include <iostream>
#include <algorithm>
using namespace std;

int N;
int answer = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;

	int num = 10;
	int i = 1;
	int j = 9;
	while (num <= N)
	{
		answer = answer + i * j;
		i++;
		j *= 10;
		num *= 10;
	}
	num /= 10;
	answer = answer + (N - num + 1) * i;
	cout << answer;

	return 0;
}