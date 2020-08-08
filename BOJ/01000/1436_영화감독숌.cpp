#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int count = 0;
	int N;
	int i = 666;
	cin >> N;
	while (1)
	{
		auto s = to_string(i);
		if (s.find("666") != string::npos)
		{
			count++;
			if (count == N)
			{
				cout << s << endl;
				return 0;
			}
		}
		i++;
	}

	return 0;
}