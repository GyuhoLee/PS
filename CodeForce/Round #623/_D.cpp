#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.first == b.first)
	{
		return a.second > b.second;
	}
	return a.first < b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	long long int answer = 0;
	pair<long long int, long long int> arr[200000];
	for (int i = 0; i < N; i++) cin >> arr[i].first;
	for (int i = 0; i < N; i++) cin >> arr[i].second;
	sort(arr, arr + N, cmp);
	int i = 0;
	while (true)
	{
		if (i == N - 1) break;
		if (arr[i].first == arr[i + 1].first)
		{
			int stay = i + 1;
			for (int j = i + 2; j < N; j++)
			{
				if (arr[i].first == arr[j].first) stay = j;
				else break;
			}
			sort(arr + i, arr + stay + 1, cmp);
			int plus = 1;
			for (int j = i + 1; j <= stay; j++)
			{
				arr[j].first += plus;
				if(stay != N - 1 && arr[stay + 1].first == arr[j].first)
				answer += (plus * arr[j].second);
				plus++;
			}
			i = stay;
		}
		else if (arr[i].first > arr[i + 1].first)
		{
			swap(arr[i], arr[i + 1]);
			i--;
			continue;
		}
		else i++;
	}
	cout << answer;


	return 0;
}