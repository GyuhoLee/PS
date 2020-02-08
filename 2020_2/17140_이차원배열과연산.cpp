#include <iostream>
#include <algorithm>
#include <string.h>
#include <limits.h>
#include <map>
#include <vector>
using namespace std;

int r, c, k;
int R = 3, C = 3;
int arr[100][100];
int answer = 0;
map<int, int> m;
vector<pair<int, int>> v;

void sortR()
{
	int big = 0;
	for (int i = 0; i < R; i++)
	{
		m.clear();
		v.clear();
		for (int j = 0; j < C; j++)
		{
			if (!arr[i][j]) continue;
			if (m.count(arr[i][j])) m[arr[i][j]]++;
			else m[arr[i][j]] = 1;
			arr[i][j] = 0;
		}
		for (auto iter : m) v.push_back(make_pair(iter.second, iter.first));
		sort(v.begin(), v.end());
		int idx = 0;
		for (auto iter : v)
		{
			arr[i][idx] = iter.second;
			arr[i][idx + 1] = iter.first;
			idx += 2;
		}
		big = max(big, idx);
	}
	C = big;
}

void sortC()
{
	int big = 0;
	for (int j = 0; j < C; j++)
	{
		m.clear();
		v.clear();
		for (int i = 0; i < R; i++)
		{
			if (!arr[i][j]) continue;
			if (m.count(arr[i][j])) m[arr[i][j]]++;
			else m[arr[i][j]] = 1;
			arr[i][j] = 0;
		}
		for (auto iter : m) v.push_back(make_pair(iter.second, iter.first));
		sort(v.begin(), v.end());
		int idx = 0;
		for (auto iter : v)
		{
			arr[idx][j] = iter.second;
			arr[idx + 1][j] = iter.first;
			idx += 2;
		}
		big = max(big, idx);
	}
	R = big;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> r >> c >> k;
	memset(arr, 0, sizeof(arr));
	for (int i = 0; i < 9; i++) cin >> arr[i / 3][i % 3];
	while (answer <= 100 && arr[r - 1][c - 1] != k)
	{
		if (R >= C) sortR();
		else sortC();
		answer++;
	}
	if (answer == 101) answer = -1;
	cout << answer;

	
	return 0;
}