#include <iostream>
#include <string>
using namespace std;

int main()
{
	int ans = 0;
	string H, N;
	cin >> H >> N;
	for (int i = 0; i <= H.length() - N.length(); i++)
	{
		ans += (H.substr(i, N.length()) == N);
	}
	cout << ans;

	return 0;
}