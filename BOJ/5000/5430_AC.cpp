#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

string P;
int N, num;
char ch;
deque<int> dq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		dq.clear();
		bool seq = true, ok = true;
		cin >> P >> N >> ch;
		if (!N) cin >> ch;
		FUP(i, 0, N - 1)
		{
			cin >> num >> ch;
			dq.push_back(num);
		}
		for(char p : P)
		{
			if (p == 'R') seq = !seq;
			else
			{
				if (dq.empty())
				{
					ok = false;
					break;
				}
				if (seq) dq.pop_front();
				else dq.pop_back();
			}
		}
		if (!ok) cout << "error\n";
		else if (seq)
		{
			cout << "[";
			for (auto iter = dq.begin(); iter != dq.end(); iter++)
			{
				cout << *iter;
				if (iter == dq.end() - 1) break;
				cout << ",";
			}
			cout << "]\n";
		}
		else
		{
			cout << "[";
			for (auto iter = dq.rbegin(); iter != dq.rend(); iter++)
			{
				cout << *iter;
				if (iter == dq.rend() - 1) break;
				cout << ",";
			}
			cout << "]\n";
		}
	}

	return 0;
}