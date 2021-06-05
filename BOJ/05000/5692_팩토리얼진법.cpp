#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	while (true)
	{
		cin >> N;
		if (!N) break;
		int num = 0, i = 1, tmp = 1;
		while (N)
		{
			num += N % 10 * tmp;
			N /= 10;
			tmp *= ++i;
		}
		cout << num << '\n';
	}

	return 0;
}