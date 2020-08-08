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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;
	int arr[8];
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	vector<int> v;
	for(int i = 0; i < M; i++) v.push_back(1);
	for (int i = M; i < N; i++) v.push_back(0);
	do
	{
		for (int i = 0; i < N; i++)
		{
			if (v[i]) cout << arr[i] << ' ';
		}
		cout << '\n';
	} while (prev_permutation(v.begin(), v.end()));

	return 0;
}