#include <iostream>
#include <algorithm>
using namespace std;

struct phone {
	int hour;
	int min;
	int time;
};

int main()
{
	int N;
	scanf("%d", &N);
	phone call[100];
	int total = 0;
	for (int i = 0; i < N; i++)
	{
		int money = 0;
		cin >> call[i].hour;
		cin.ignore();
		cin >> call[i].min >> call[i].time;
		if (call[i].hour >= 19 || call[i].hour <= 5)
		{
			money += call[i].time * 5;
		}
		else if (call[i].hour == 6)
		{
			if (call[i].min + call[i].time > 60)
			{
				money += (call[i].min + call[i].time - 60) * 10;
				money += (60 - call[i].min) * 5;
			}
			else money += call[i].time * 5;
		}
		else if (call[i].hour == 18)
		{
			if (call[i].min + call[i].time > 60)
			{
				money += (call[i].min + call[i].time - 60) * 5;
				money += (60 - call[i].min) * 10;
			}
			else money += call[i].time * 10;
		}
		else {
			money += call[i].time * 10;
		}
		total += money;
	}
	cout << total << endl;




	return 0;
}