#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N;
string str[50];
string answer = "";

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> str[i];
}

void solve()
{
	for (int i = 0; i < str[0].length(); i++)
	{
		bool equal = true;
		char temp = str[0][i];
		for (int j = 1; j < N; j++)
		{
			if (temp != str[j][i])
			{
				equal = false;
				break;
			}
		}
		answer += equal ? temp : '?';
	}
	cout << answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();

	
	return 0;
}