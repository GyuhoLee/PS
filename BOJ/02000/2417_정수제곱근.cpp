#include <iostream>
#include <math.h>
using namespace std;

long long N, l, r, mid, ans;

int main()
{
	cin >> N;
	l = 1, r = N;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (mid >= sqrt(N))
		{
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans;

	return 0;
}