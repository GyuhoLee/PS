#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <string>
#include <string.h>
#include <limits.h>
using namespace std;

int N, M;
int arr[8];
int visited[8];

void func(int idx, int start, int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << arr[visited[i]] << " ";
		}
		cout << "\n";
		return;
	}

	if (idx == N)
	{
		return;
	}

	for (int i = start; i < N; i++)
	{
		visited[idx] = i;
		func(idx + 1, i, cnt + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	func(0, 0, 0);

	return 0;
}