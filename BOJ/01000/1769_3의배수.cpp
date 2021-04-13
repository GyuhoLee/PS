#include <iostream>
#include <string>
using namespace std;

int main()
{
	int cnt = 0;
	string X;
	cin >> X;
	while (X.length() > 1)
	{
		cnt++;
		int tmp = 0;
		for (char ch : X)
		{
			tmp += (int)(ch - '0');
		}
		X = to_string(tmp);
	}
	int tmp = stoi(X);
	cout << cnt << '\n';
	cout << (tmp % 3 ? "NO" : "YES");

	return 0;
}