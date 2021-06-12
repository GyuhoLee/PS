#include <iostream>
#include <map>
#include<set>
using namespace std;

map<int, int> X, Y;
int N, x, y, ans = 0;


int main()
{
	cin >> N;
	while (N--)
	{
		cin >> x >> y;
		X[x]++;
		Y[y]++;
	}
	for (auto p : X) ans += p.second > 1;
	for (auto p : Y) ans += p.second > 1;
	cout << ans;
	return 0;
}