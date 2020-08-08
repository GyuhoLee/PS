#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N;
string temp;
string str;
string answer;

void solve(int i, int j)
{
	if (i == str.length() - 1 && j == temp.length() - 1)
	{
		answer = "DA";
		return;
	}
	if (i == str.length() || j == temp.length()) return;
	if (str[i] == temp[j])
	{
		solve(i + 1, j + 1);
	}
	if (str[i] == '*')
	{
		solve(i, j + 1);
		if (str[i + 1] == temp[j])
		{
			if (i + 2 == str.length())
			{
				if (j == temp.length() - 1) answer = "DA";
				else return;
			}
			else solve(i + 2, j + 1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	cin >> str;
	while (N--)
	{
		cin >> temp;
		answer = "NE";
		solve(0, 0);
		cout << answer << '\n';
	}

	return 0;
}