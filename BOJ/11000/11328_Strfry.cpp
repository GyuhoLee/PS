#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int N;
string a, b;

int main()
{
	cin >> N;
	while (N--)
	{
		cin >> a >> b;
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		if (a == b) cout << "Possible\n";
		else cout << "Impossible\n";
	}
}