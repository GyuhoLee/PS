#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define F(i, a, b) for(int i = a; i < b; i++)
#define MS(a, b) memset(a, b, sizeof(a))

int cnt = 0;
int answer = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;
	F(i, 0, str.length())
	{
		if (str[i] == '(')
		{
			if (str[i + 1] == ')')
			{
				answer += cnt;
				i++;
			}
			else
			{
				answer++;
				cnt++;
			}
		}
		else cnt--;
	}
	cout << answer;

	return 0;
}