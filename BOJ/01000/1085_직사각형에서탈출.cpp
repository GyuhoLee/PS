#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int x, y, a, b;
	cin >> x >> y >> a >> b;
	int answer = min(a - x, x);
	answer = min(answer, y);
	answer = min(answer, b - y);
	cout << answer;
	return 0;
}