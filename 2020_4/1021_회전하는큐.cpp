#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N, M;
int answer = 0;
deque<int> dq;
deque<int> temp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	FUP(i, 1, N) dq.push_back(i);
	while (M--)
	{
		int num;
		cin >> num;
		if (dq.front() == num)
		{
			dq.pop_front();
			continue;
		}
		int Right = 0, Left = 0;
		int now = -1;
		while (now != num)
		{
			Right++;
			now = dq.back();
			temp.push_back(now);
			dq.pop_back();
		}
		while (!temp.empty())
		{
			dq.push_back(temp.back());
			temp.pop_back();
		}
		now = -1;
		while (now != num)
		{
			temp.push_back(dq.front());
			dq.pop_front();
			now = dq.front();
			Left++;
		}
		dq.pop_front();
		while (!temp.empty())
		{
			dq.push_back(temp.front());
			temp.pop_front();
		}
		answer += min(Left, Right);
	}

	cout << answer;

	return 0;
}