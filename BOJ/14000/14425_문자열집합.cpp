#include <iostream>
#include <string>
#include <set>
using namespace std;
int N, M, ans = 0;
string str;
set<string> S;

int main()
{
	cin >> N >> M;
	while (N--)
	{
		cin >> str;
		S.insert(str);
	}
	while (M--)
	{
		cin >> str;
		ans += S.count(str);
	}
	cout << ans;

	return 0;
}