#include <iostream>
using namespace std;

int main()
{
	int N, M, iter = 1, J, j, ans = 0;
	cin >> N >> M >> J;
	while (J--)
	{
		cin >> j;
		if (j < iter)
		{
			ans += iter - j;
			iter = j;
		}
		else if (iter + M <= j)
		{
			ans += j - M + 1 - iter;
			iter = j - M + 1;
		}
	}
	cout << ans;

	return 0;
}