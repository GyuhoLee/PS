#include <iostream>
using namespace std;

int N, num;
bool visited[10000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (visited[num]) cout << num;
		visited[num] = true;
	}

}