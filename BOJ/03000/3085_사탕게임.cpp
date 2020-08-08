#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<char>> arr;
int answer = 1;
int N;

void check_row();
void check_col();

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		vector<char> element(N);
		arr.push_back(element);
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N ; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			swap(arr[i][j], arr[i][j + 1]);
			check_row();
			check_col();
			swap(arr[i][j], arr[i][j + 1]);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			swap(arr[j][i], arr[j + 1][i]);
			check_row();
			check_col();
			swap(arr[j][i], arr[j + 1][i]);
		}
	}

	cout << answer;

	return 0;
}

void check_row()
{
	for (int i = 0; i < N; i++)
	{
		char before = arr[i][0];
		int count = 1;
		for (int j = 1; j < N; j++)
		{
			if (before == arr[i][j]) count++;
			else
			{
				if (count > answer) answer = count;
				before = arr[i][j];
				count = 1;
			}
		}
		if (count > answer) answer = count;
	}
}

void check_col()
{
	for (int i = 0; i < N; i++)
	{
		char before = arr[0][i];
		int count = 1;
		for (int j = 1; j < N; j++)
		{
			if (before == arr[j][i]) count++;
			else
			{
				if (count > answer) answer = count;
				before = arr[j][i];
				count = 1;
			}
		}
		if (count > answer) answer = count;
	}
}