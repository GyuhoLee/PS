#include <iostream>
#include <queue>
using namespace std;

int T, N, num, visited[1000000];
char oper;

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> N;
		priority_queue<pair<int, int>> maxQ;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minQ;
		for (int i = 0; i < N; i++)
		{
			visited[i] = false;
			cin >> oper >> num;
			if (oper == 'I')
			{
				maxQ.push({ num, i });
				minQ.push({ num, i });
			}
			else
			{
				while (!maxQ.empty() && visited[maxQ.top().second]) { maxQ.pop(); };
				while (!minQ.empty() && visited[minQ.top().second]) { minQ.pop(); };
				if (maxQ.empty()) continue;
				if (num == 1)
				{
					visited[maxQ.top().second] = true;
					maxQ.pop();
				}
				else
				{
					visited[minQ.top().second] = true;
					minQ.pop();
				}
			}
		}
		while (!maxQ.empty() && visited[maxQ.top().second]) { maxQ.pop(); };
		while (!minQ.empty() && visited[minQ.top().second]) { minQ.pop(); };
		if (maxQ.empty()) cout << "EMPTY\n";
		else cout << maxQ.top().first << ' ' << minQ.top().first << '\n';
	}

	return 0;
}