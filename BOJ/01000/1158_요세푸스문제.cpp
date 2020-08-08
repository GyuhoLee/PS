#include <bits/stdc++.h>
using namespace std;
#define ll long long int

queue<int> q;
int N, K;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) q.push(i);
	cout << "<";
	while (q.size() != 1)
	{
		for (int i = 1; i < K; i++)
		{
			int temp = q.front();
			q.pop();
			q.push(temp);
		}
		cout << q.front() << ", ";
		q.pop();
	}
	cout << q.front() << ">";
	

	return 0;
}