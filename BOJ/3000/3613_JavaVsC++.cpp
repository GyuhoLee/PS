#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string str;
bool isJ = false;
bool isC = false;
bool jjap = false;

void language()
{
	cin >> str;
	char before = 'z';
	for (auto s : str)
	{
		if (s >= 'A' && s <= 'Z') isJ = true;
		if (s == '_')
		{
			if (before == '_') jjap = true;
			isC = true;
		}
		before = s;
	}
	if (str[0] == '_' || str.back() == '_' || (str[0] >= 'A' && str[0] <= 'Z')) jjap = true;
}

void jToC()
{
	string answer = "";
	for (auto s : str)
	{
		if (s >= 'A' && s <= 'Z')
		{
			answer += '_';
			answer += (char)(s + ('a' - 'A'));
		}
		else answer += s;
	}
	cout << answer;
}

void cToJ()
{
	string answer = "";
	bool before = false;
	for (auto s : str)
	{
		if (s == '_')
		{
			before = true;
			continue;
		}
		if (!before) answer += s;
		else
		{
			answer += (char)(s - ('a' - 'A'));
			before = false;
		}
	}
	cout << answer;
}

void solve()
{
	if (jjap || (isJ&& isC)) cout << "Error!";
	else if (isJ) jToC();
	else if (isC) cToJ();
	else cout << str;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	language();
	solve();

	return 0;
}