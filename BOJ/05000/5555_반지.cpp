#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N, ans = 0;
	string str, tmp;
	cin >> str >> N;
	while (N--)
	{
		cin >> tmp;
		tmp += tmp;
		ans += (tmp.find(str) != string::npos);
	}
	cout << ans;

	return 0;
}