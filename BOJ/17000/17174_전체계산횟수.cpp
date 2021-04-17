#include <iostream>
using namespace std;

int main()
{
	int N, M, ans = 0;
	cin >> N >> M;
	while (N)
	{
		ans += N;
		N /= M;
	}
	cout << ans;

	return 0;
}