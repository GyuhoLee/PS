#include <iostream>
#include <algorithm>
using namespace std;

long long int arr[200001];
long long int v[200001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < N; i++) cin >> v[i];
	long long int answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			int r, l;
			if (arr[i] < arr[j])
			{
				r = j;
				l = i;
			}
			else
			{
				r = i;
				l = j;
			}
			long long int dist = arr[r] - arr[l];
			long long int speed = v[r] - v[l];
			if (dist == 0 || speed < 0) continue;
			answer += dist;
		}
	}
	cout << answer;

	return 0;
}