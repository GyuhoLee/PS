#include <iostream>
#include <vector>
using namespace std;

vector<int> answer(100001);

int main()
{
	int N;
	cin >> N;
	answer[0] = 1;
	answer[1] = 3;
	for (int i = 2; i <= N; i++)
	{
		answer[i] = (answer[i - 2] + 2 * answer[i - 1]) % 9901;
	}
	cout << answer[N];
	

	return 0;
}