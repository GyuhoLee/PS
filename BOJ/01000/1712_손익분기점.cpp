#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long long int A, B, C;
	cin >> A >> B >> C;
	if (B >= C)
	{
		cout << "-1";
		return 0;
	}
	long long int cnt = A / (C - B) + 1;
	cout << cnt;
	return 0;
}
