#include <iostream>
using namespace std;

int N, cow[11], idx, num, ans = 0;

int main()
{
	for (int i = 1; i <= 10; i++) cow[i] = -1;
	cin >> N;
	while (N--)
	{
		cin >> idx >> num;
		if (cow[idx] == -1) cow[idx] = num;
		else if (cow[idx] != num)
		{
			ans++;
			cow[idx] = num;
		}
	}
	cout << ans;
	return 0;
}