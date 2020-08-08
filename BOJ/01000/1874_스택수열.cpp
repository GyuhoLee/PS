#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N;
int arr[100000];
stack<int> S;
vector<char> answer;
int cnt = 1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	FUP(i, 0, N - 1)
	{
		int num;
		cin >> num;
		
		if (S.empty() || S.top() != num)
		{
			while (true)
			{
				if (cnt > num)
				{
					cout << "NO";
					return 0;
				}
				S.push(cnt++);
				answer.push_back('+');
				if (S.top() == num)
				{
					S.pop();
					answer.push_back('-');
					break;
				}
			}
		}
		else
		{
			S.pop();
			answer.push_back('-');
		}
	}

	for (char c : answer)
	{
		cout << c << '\n';
	}

	return 0;
}