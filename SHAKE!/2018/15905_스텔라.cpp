#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int stu[66][2];
	for (int i = 0; i < N; i++)
	{
		cin >> stu[i][0] >> stu[i][1];
	}
	int max = 5;
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		if (stu[i][0] == 8 && max == 0) answer++;
		else if (stu[i][0] == 8) max--;
	}
	if (max)
	{
		for (int i = 0; i < N; i++)
		{
			if (stu[i][0] == 7 && max == 0) answer++;
			else if (stu[i][0] == 7) max--;
		}
	}
	if (max)
	{
		for (int i = 0; i < N; i++)
		{
			if (stu[i][0] == 6 && max == 0) answer++;
			else if (stu[i][0] == 6) max--;
		}
	}
	if (max)
	{
		for (int i = 0; i < N; i++)
		{
			if (stu[i][0] == 5 && max == 0) answer++;
			else if (stu[i][0] == 5) max--;
		}
	}
	if (max)
	{
		for (int i = 0; i < N; i++)
		{
			if (stu[i][0] == 4 && max == 0) answer++;
			else if (stu[i][0] == 4) max--;
		}
	}
	if (max)
	{
		for (int i = 0; i < N; i++)
		{
			if (stu[i][0] == 3 && max == 0) answer++;
			else if (stu[i][0] == 3) max--;
		}
	}
	if (max)
	{
		for (int i = 0; i < N; i++)
		{
			if (stu[i][0] == 2 && max == 0) answer++;
			else if (stu[i][0] == 2) max--;
		}
	}
	if (max)
	{
		for (int i = 0; i < N; i++)
		{
			if (stu[i][0] == 1 && max == 0) answer++;
			else if (stu[i][0] == 1) max--;
		}
	}

	cout << answer;


	return 0;
}