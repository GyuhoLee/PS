#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;
	string answer;
	cin >> str;
	if (str == "0")
	{
		cout << 0;
		return 0;
	}
	for (auto a : str)
	{
		if (a == '0') answer += "000";
		else if (a == '1') answer += "001";
		else if (a == '2') answer += "010";
		else if (a == '3') answer += "011";
		else if (a == '4') answer += "100";
		else if (a == '5') answer += "101";
		else if (a == '6') answer += "110";
		else if (a == '7') answer += "111";
	}
	int i = 0;
	if (answer[0] == '0')
	{
		i = 1;
		if (answer[1] == '0') i = 2;
	}
	for (; i < answer.length(); i++)
	{
		cout << answer[i];
	}

	return 0;
}