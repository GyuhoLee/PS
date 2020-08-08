#include <iostream>
using namespace std;

int main()
{
	
	int N, M;
	
	
	while (1)
	{
		int count = 0;
		cin >> N;
		if (cin.eof())
			break;
		cin >> M;
		for (int i = N; i <= M; i++)
		{
			if (i >= 10 && i <= 99)
			{
				int hold1 = i / 10;
				int hold2 = i % 10;
				if (hold1 == hold2)
				{
					count += 1;
				}
			}
			if (i >= 100 && i <= 999)
			{
				int hold1 = i / 100;
				int hold2 = i / 10 % 10;
				int hold3 = i % 10;
				if (hold1 == hold2 || hold1 == hold3 || hold2 == hold3)
				{
					count += 1;
				}
			}
			if (i >= 1000 && i <= 5000)
			{
				int hold1 = i / 1000;
				int hold2 = i / 100 % 10;
				int hold3 = i / 10 % 10 ;
				int hold4 = i % 10;
				if (hold1 == hold2 || hold1 == hold3 || hold1 == hold4 || hold2 == hold3 || hold2 == hold4 || hold3 == hold4)
				{
					count += 1;
				}
			}
		}
		cout << (M - N + 1) - count << endl;
	}


	return 0;
}