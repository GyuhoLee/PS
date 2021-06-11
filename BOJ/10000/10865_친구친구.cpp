#include <iostream>
using namespace std;

int N, M, a, b, arr[100001];
int main()
{
	cin >> N >> M;
	while (M--)
	{
		cin >> a >> b;
		arr[a]++; arr[b]++;
	}
	for (int i = 1; i <= N; i++)
	{
		cout << arr[i] << '\n';
	}

	return 0;
}