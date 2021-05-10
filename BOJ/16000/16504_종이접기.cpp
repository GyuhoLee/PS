#include <iostream>
using namespace std;

int main()
{
	long long N, tmp, ans = 0;
	cin >> N;
	N *= N;
	while (N--)
	{
		cin >> tmp;
		ans += tmp;
	}
	cout << ans;

	return 0;
}