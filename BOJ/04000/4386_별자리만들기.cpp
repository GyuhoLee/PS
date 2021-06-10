#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int N;
double dist[100][100], ans = 0;
pair<double, double> arr[100];
bool visited[100];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].first >> arr[i].second;
		for (int j = 0; j < i; j++)
		{
			dist[i][j] = dist[j][i] = sqrt(pow(arr[i].first - arr[j].first, 2) + pow(arr[i].second - arr[j].second, 2));
		}
	}
	priority_queue<pair<double, int>> pq;
	visited[0] = true;
	for (int i = 1; i < N; i++)
	{
		pq.push({ -dist[0][i], i });
	}
	while (!pq.empty())
	{
		double d = -pq.top().first;
		int idx = pq.top().second;
		pq.pop();
		if (visited[idx]) continue;
		visited[idx] = true;
		ans += d;
		for (int i = 0; i < N; i++)
		{
			if (visited[i]) continue;
			pq.push({ -dist[idx][i], i });
		}
	}
	cout << ans;

	return 0;
}