#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int N, h, L;
	cin >> N >> L;
	priority_queue<int, vector<int>, greater<int>> pq;
	while (N--)
	{
		cin >> h;
		pq.push(h);
	}
	while (!pq.empty() && pq.top() <= L)
	{
		L++;
		pq.pop();
	}
	cout << L;
	return 0;
}