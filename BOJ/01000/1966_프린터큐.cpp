#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int T;
int N, M;
queue<pair<int, int>> printer;
vector<int> important;

void input()
{
	while (!printer.empty()) printer.pop();
	important.clear();
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		printer.push(make_pair(i, temp));
		important.push_back(temp);
	}
	sort(important.begin(), important.end());
}

void solve()
{
	int answer = 1;
	while (true)
	{
		int num = printer.front().first;
		int priority = printer.front().second;
		printer.pop();
		if (priority == important.back())
		{
			if (num == M)
			{
				break;
			}
			else
			{
				answer++;
				important.pop_back();
			}
		}
		else
		{
			printer.push(make_pair(num, priority));
		}
	}
	cout << answer << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--)
	{
		input();
		solve();
	}

	return 0;
}