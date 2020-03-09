#include <bits/stdc++.h>
using namespace std;

map<string, int> m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	m["black"] = 0;
	m["brown"] = 1;
	m["red"] = 2;
	m["orange"] = 3;
	m["yellow"] = 4;
	m["green"] = 5;
	m["blue"] = 6;
	m["violet"] = 7;
	m["grey"] = 8;
	m["white"] = 9;

	string str1, str2, str3;
	cin >> str1 >> str2 >> str3;
	long long int answer = 10 * m[str1] + m[str2];
	int x = 1;
	for (int i = 0; i < m[str3]; i++) x *= 10;
	cout << answer * x;

	return 0;
}