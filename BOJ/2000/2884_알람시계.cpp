#include <iostream>
using namespace std;

int main()
{
	int H, M;
	cin >> H >> M;
	M -= 45;
	if (0 > M)
	{
		H--;
		if (H < 0) H = 23;
		M += 60;
	}
	cout << H << " " << M;

	return 0;
}