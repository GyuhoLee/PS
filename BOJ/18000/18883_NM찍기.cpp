#include <iostream>
using namespace std;

int main()
{
	int N, M, num = 1;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << num++;
			if (j != M - 1) cout << ' ';
		}
		cout << '\n';
	}

	return 0;
}