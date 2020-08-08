#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

deque<int> dq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	while (N--)
	{
		string str;
		cin >> str;
		if (str == "push_front")
		{
			int num;
			cin >> num;
			dq.push_front(num);
		}
		else if (str == "push_back")
		{
			int num;
			cin >> num;
			dq.push_back(num);
		}
		else if (str == "pop_front")
		{
			if (dq.empty()) cout << "-1\n";
			else
			{
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (str == "pop_back")
		{
			if (dq.empty()) cout << "-1\n";
			else
			{
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (str == "size") cout << dq.size() << '\n';
		else if (str == "empty")
		{
			if (dq.empty()) cout << "1\n";
			else cout << "0\n";
		}
		else if (str == "front")
		{
			if (dq.empty()) cout << "-1\n";
			else
			{
				cout << dq.front() << '\n';
			}
		}
		else if (str == "back")
		{
			if (dq.empty()) cout << "-1\n";
			else
			{
				cout << dq.back() << '\n';
			}
		}
	}

	return 0;
}