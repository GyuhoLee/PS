#include <iostream>
using namespace std;

int main()
{
	int i = 0;
	while (true)
	{
		i++;
		int a;
		cin >> a;
		if (!a) break;
		cout << i << ". ";
		if (a % 2) cout << "odd ";
		else cout << "even ";
		cout << a / 2 << '\n';
	}

	return 0;
}