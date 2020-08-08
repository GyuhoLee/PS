#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		pair<double, string> temp;
		cin >> temp.first >> temp.second;
		if (temp.second == "kg") printf("%.4lf lb\n", temp.first * 2.2046);
		else if (temp.second == "lb") printf("%.4lf kg\n", temp.first * 0.4536);
		else if (temp.second == "l") printf("%.4lf g\n", temp.first * 0.2642);
		else if (temp.second == "g") printf("%.4lf l\n", temp.first * 3.7854);
	}


	return 0;
}