#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	queue<int> q;
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) q.push(i);
	while (!q.empty())
	{
		cout << q.front() << ' ';
		q.pop();
		if (!q.empty())
		{
			int num = q.front();
			q.push(num);
			q.pop();
		}
	}


	return 0;
}